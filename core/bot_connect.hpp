#include <boost/asio.hpp>
#include <boost/test/unit_test.hpp>

#include <functional>

class Server
{
public:
    Server(const char* _SetAddress, const unsigned short _SetPort);
    ~Server();

    inline
    unsigned short get_port() const
    { return this->port; }

    inline
    const char* get_address() const
    { return this->address; }

    void connect();
    void reconnect();
    void disconnect();
    void read();
    void send();
    void run();
    void stop();
    void wait();

private:
    const char* address;
    const unsigned short port;

    std::function <void()> on_connect;

    boost::asio::io_service server_io;
    boost::asio::ip::tcp::endpoint PointToConnect;
    boost::asio::ip::tcp::socket ServerSocket;

};

class Client
{

};
