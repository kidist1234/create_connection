#include "atcsender.h"
#include <iostream>

atcsender::atcsender(std::string url, zmq::context_t& context, zmq::socket_type type)
    : socket(context, type)
{
    ip = url;
    socket.bind(ip); 
}

void atcsender::send(std::string message) {
    zmq::message_t zmq_message(message.size());
    memcpy(zmq_message.data(), message.data(), message.size());
   auto result = socket.send(zmq_message, zmq::send_flags::none);
    if (result) {
        std::cout << "response sent successfully: " <<std::endl<<message << std::endl;  
    } else {
        std::cerr << "Failed to send message: " << std::endl<<message << std::endl;  
    }
}

atcsender::~atcsender() {
    std::cout<<"sender destructur"<<std::endl;
}