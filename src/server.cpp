

#include "connection_handler.h"
#include <iostream>

int main(int argc, char **argv)
{
  std::cout << "Starting Server\n";

  try
  {
    ConnectionHandler handler; // Allocate on stack

    // Optional: Process command-line arguments if needed
    // if (argc > 1) {
    //     // Example: Set port number or other configurations
    // }

    if (handler.Connect() != 0)
    {
      std::cerr << "Failed to start server\n";
      return 1;
    }
    if (handler.SendResponse200() != 0)
    {
      std::cerr << "Failed to send response\n";
      return 1;
    }
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << "Exception caught: " << e.what() << "\n";
    return 1;
  }

  std::cout << "Server started successfully\n";
  return 0;
}

