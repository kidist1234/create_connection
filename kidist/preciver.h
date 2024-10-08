#include <zmq.hpp>
#include <string>
#include <iostream>

class preciver
{
private:
    zmq::socket_t socket;

public:
    preciver(std::string url, zmq::context_t& context, zmq::socket_type type);
    ~preciver();
    std::string ip = "";
    void receive();  
};
