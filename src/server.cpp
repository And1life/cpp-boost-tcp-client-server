#include "server.hpp"

TCPServer::TCPServer(boost::asio::io_context &io_context, short port) : acceptor_(io_context,
     boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}

void TCPServer::start()
{
    std::cout << "The server is running. Waiting for connection..." << std::endl;
    accept_connection();
}
