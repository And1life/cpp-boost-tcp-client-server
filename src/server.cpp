#include "server.hpp"

TCPServer::TCPServer(boost::asio::io_context &io_context, short port) : acceptor_(io_context,
     boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}