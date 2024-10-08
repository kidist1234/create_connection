#include <string>
#include <zmq.hpp>
#include <iostream>
#include "preciver.h"

class psender
{
private:
    zmq::socket_t socket;
    preciver receiver;

public:
    psender(std::string url, zmq::context_t& context, zmq::socket_type type);
    std::string ip = "";
    void sender(std::string message);
    ~psender();
};
