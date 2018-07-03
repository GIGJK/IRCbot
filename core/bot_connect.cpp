#include "bot_connect.hpp"

Server::Server(const char* SetAddress, const unsigned short _SetPort) :
    address(SetAddress),
    port(_SetPort),
    ServerSocket(server_io)
{
    // Initialize endpoint and run io_service

    PointToConnect.address(boost::asio::ip::address::from_string(this->address));
    PointToConnect.port(this->port);

    this->server_io.run();
}

Server::~Server()
{
    // Close io_service and ServerSocket
    this->ServerSocket.close();
    this->server_io.stop();
}

void Server::connect()
{
    ServerSocket.connect(PointToConnect);
}

void Server::disconnect()
{
    ServerSocket.close();
}
