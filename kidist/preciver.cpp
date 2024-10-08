#include "preciver.h"
#include <zmq.hpp>
#include <iostream>

preciver::preciver(std::string url, zmq::context_t& context, zmq::socket_type type)
    : socket(context, type)
{
    ip = url;
            socket.connect(ip);
          
}

preciver::~preciver()
{
    std::cout << "In receiver Socket Destructor" << std::endl;
}

void preciver::receive()
{
    zmq::message_t reply; 

    std::optional<long unsigned int> s = socket.recv(reply, zmq::recv_flags::none);
    std::string received_message(static_cast<char*>(reply.data()), reply.size());

    if (s) { 
        std::cerr << "Received message: " << received_message << std::endl; 
    } else {
        std::cerr << "Failed to receive message." << std::endl; 
    }
}
