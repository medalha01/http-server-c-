#include "connection_handler.h"
#include "http_constants.h"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <netdb.h>

ConnectionHandler::ConnectionHandler()
{
    std::cout << "Starting Server\n";
    this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server_socket == -1)
    {
        std::cerr << "Failed to create server socket\n";
        this->error = true;
        throw std::runtime_error("Failed to create server socket");
    }
    std::cout << "Server socket created.\n";
    if (setsockopt(this->server_socket, SOL_SOCKET, SO_REUSEPORT, &this->reuse, sizeof(this->reuse)) < 0)
    {
        std::cerr << "setsockopt failed\n";
        std::cerr << "Error: " << strerror(errno) << "\n";
        this->error = true;
        throw std::runtime_error("setsockopt failed");
    }
    std::cout << "Server socket REUSE PORT set.\n";

    // AF_INET refers to addresses from the internet, IP addresses specifically.
    this->socket_address.sin_family = AF_INET;
    // INADDR_ANY means that the socket will bind to all available interfaces.
    // Other options are a specific IP address or localhost.
    this->socket_address.sin_addr.s_addr = INADDR_ANY;
    // htons converts the port number from host byte order to network byte order.
    this->socket_address.sin_port = htons(port);
}

ConnectionHandler::~ConnectionHandler()
{
    std::cout << "Closing server socket.\n";
    close(this->server_socket);
}

int ConnectionHandler::Connect()
{
    // bind assigns the address specified by socket_address to the socket.
    if (bind(server_socket, (struct sockaddr *)&this->socket_address, sizeof(this->socket_address)) != 0)
    {
        std::cerr << "Failed to bind to port 4221\n";
        return 1;
    }
    std::cout << "Server socket bound to port 4221.\n";
    // listen sets the socket to listen for incoming connections.
    // The second argument is the backlog, or the number of pending connections
    // that can be queued up before connections are refused.
    if (listen(server_socket, 10) != 0)
    {
        std::cerr << "listen failed\n";
        return 1;
    }
    std::cout << "Server socket listening.\n";

    std::cout << "Waiting for a client\n";
    // accept blocks until a client connects to the server.
    // It returns a new socket that can be used to communicate with the client.
    client_socket = accept(server_socket, (struct sockaddr *)&this->client_address, &this->client_address_len);
    if (client_socket == -1)
    {
        std::cerr << "Failed to accept client\n";
        return 1;
    }
    std::cout << "Client connected\n";

    recv(client_socket, buffer, buffer_size, 0);

    // The server can communicate with the client using send and recv.

    return 0;
}

int ConnectionHandler::SendResponse200()
{
    try
    {
        size_t totalLength = strlen(http_constants.HTTP_VERSION) + strlen(http_constants.HTTP_OK) + 2 * strlen(http_constants.HTTP_CRLF);
        char concatenatedString[totalLength + 1];
        strcpy(concatenatedString, http_constants.HTTP_VERSION);
        strcat(concatenatedString, http_constants.HTTP_OK);
        strcat(concatenatedString, http_constants.HTTP_CRLF);
        strcat(concatenatedString, http_constants.HTTP_CRLF);
        std::string response = concatenatedString;
        std::cout << response << std::endl;
        send(this->client_socket, response.c_str(), response.length(), 0);
        std::cout << "Hello message sent\n";
        close(this->server_socket);
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << "\n";
        return 1;
    }
}
void ConnectionHandler::GetClientRequest()
{
    char buffer[1024] = {0};
    int valread = read(this->server_socket, buffer, 1024);
    std::cout << buffer << std::endl;
    std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 12\r\n\r\nHello World!";
    send(this->server_socket, response.c_str(), response.length(), 0);
    std::cout << "Hello message sent\n";
    // close(this->server_socket);
}
