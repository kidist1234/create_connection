#include <zmq.hpp>
#include <string>
#include <iostream>

class TowerSender
{

private:
    zmq::context_t ctx;
    zmq::socket_t socket;



public:
    TowerSender(std::string url, zmq::context_t& context, zmq::socket_type type);
    ~TowerSender();

    std::string ip = "";

    void print(std::string msg);

    void start();
    void send(std::string message);
    void close();

};

