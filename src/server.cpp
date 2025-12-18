#include "server.hpp"

TCPServer::TCPServer(boost::asio::io_context &io_context, short port) : acceptor_(io_context,
     boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}

void TCPServer::start()
{
    while (true)
    {
        std::cout << "The server is running. Waiting for connection..." << std::endl;
    
        accept_connection();
    }
    
    
}

void TCPServer::accept_connection()
{
    boost::asio::ip::tcp::socket socket(acceptor_.get_executor());

    acceptor_.accept(socket);
    std::cout << "The client has connected!" << std::endl;

    while (true)
    {
        boost::asio::streambuf buf;
        boost::system::error_code ec;

        boost::asio::read_until(socket, buf, '\n', ec);

        if (ec == boost::asio::error::eof)
        {
            std::cout << "Client disconnected\n";
            break;
        } else if (ec)
        {
            throw boost::system::system_error(ec);
        }
        
        std::istream is(&buf);
        std::string message;
        std::getline(is, message);
    
        std::cout << "Message received: " << message << std::endl;
    
        boost::asio::write(socket, boost::asio::buffer("Message received!\n"));
    }
    


}
