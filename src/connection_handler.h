#ifndef CONNECTION_HANDLER_H
#define CONNECTION_HANDLER_H

#include "http_constants.h"

#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

struct Request
{
    char *method = NULL;
    char *path = NULL;
    char *version = NULL;
    char *host = NULL;
    char *user_agent = NULL;
    char *accept = NULL;
    char *accept_language = NULL;
    char *accept_encoding = NULL;
    char *connection = NULL;
    char *content_type = NULL;
    char *content_length = NULL;
    char *body = NULL;
};

class ConnectionHandler
{
public:
    ConnectionHandler();
    ~ConnectionHandler();
    int Connect();
    void GetClientRequest();
    int SendResponse200();
    Request RequestParser();
    int ResponseParser();
    Request request;

    // virtual void handle() = 0;

private:
    HTTP_CONSTANTS http_constants;
    // sockaddr_in *socket_address = new sockaddr_in;
    sockaddr_in socket_address;
    sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    // AF_INET refers to addresses from the internet, IP addresses specifically.
    // SOCK_STREAM provides sequenced, reliable, two-way, connection-based byte streams.
    int server_socket;
    int client_socket;
    int reuse = 1;
    bool error = false;
    int16_t port = 4221;
    static const int buffer_size = 2048;
    char buffer[buffer_size + 1];
};

#endif // CONNECTION_HANDLER_H
