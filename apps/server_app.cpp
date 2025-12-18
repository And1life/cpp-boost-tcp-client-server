#include "server.hpp"

int main()
{
    boost::asio::io_context io_context;

    TCPServer server(io_context, 1234);

    server.start();

    return 0;
}