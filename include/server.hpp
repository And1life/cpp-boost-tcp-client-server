#pragma once

#include <boost/asio.hpp>
#include <iostream>

class TCPServer
{

public:

    TCPServer(boost::asio::io_context& io_context, short port);

    void start();

private:

    boost::asio::ip::tcp::acceptor acceptor_;

    void accept_connection();

};

