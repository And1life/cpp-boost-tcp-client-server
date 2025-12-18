#pragma once

#include <boost/asio.hpp>
#include <iostream>
#include <string>

class TCPClient
{

public:
    
    TCPClient(boost::asio::io_context& io_context, const std::string& host, short port);

    void send_message(const std::string& message);

private:

    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::resolver resolver_;
    
};
