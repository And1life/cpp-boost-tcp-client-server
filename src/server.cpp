#include "server.hpp"

TCPServer::TCPServer(boost::asio::io_context &io_context, short port) : acceptor_(io_context,
     boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
     socket_ (io_context) 
     {}

void TCPServer::start()
{
    std::cout << "The server is running. Waiting for connection..." << std::endl;
    accept_connection();
}

void TCPServer::accept_connection()
{

    acceptor_.accept(socket_);
    std::cout << "The client has connected!" << std::endl;

    boost::asio::streambuf buf;

    boost::asio::read_until(socket_, buf, '\n');

    std::istream is(&buf);
    std::string message;
    std::getline(is, message);

    std::cout << "Message received: " << message << std::endl;

    boost::asio::write(socket_, boost::asio::buffer("Message received!\n"));

    accept_connection();
}
