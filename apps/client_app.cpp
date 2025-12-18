#include "client.hpp"
#include <iostream>

int main()
{
    boost::asio::io_context io_context;

    TCPClient client(io_context, "127.0.0.1", 1234);

    while (true)
    {
        std::cout << "Print message: ";
        std::string message;
        std::getline(std::cin, message);
    
        client.send_message(message);
    }
    


    return 0;
}
