#include "client.hpp"

TCPClient::TCPClient(boost::asio::io_context &io_context, const std::string &host, short port)
    : socket_(io_context), resolver_(io_context)
{
    boost::asio::ip::tcp::resolver::query query(host, std::to_string(port));
    boost::asio::ip::tcp::resolver::results_type endpoints = resolver_.resolve(query);

    boost::asio::connect(socket_, endpoints);
}