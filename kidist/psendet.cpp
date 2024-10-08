#include "psender.h"
#include <zmq.hpp>
#include <thread>

psender::psender(std::string url, zmq::context_t& context, zmq::socket_type type)
    : socket(context, type), receiver{"tcp://localhost:5558", context, zmq::socket_type::pull}
{
    ip = url;
    socket.bind(ip);  
}

psender::~psender()
{
    std::cout << "In sender Socket Destructor" << std::endl;
}

void psender::sender(std::string message)
{
    zmq::message_t zmq_message(message.size());
    memcpy(zmq_message.data(), message.data(), message.size()); 

    socket.send(zmq_message, zmq::send_flags::none); 
    std::cerr << "Sent: " << message << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));  
    receiver.receive();  
}

int main()
{
    zmq::context_t ctx(1);  
    psender sender{"tcp://*:5557", ctx, zmq::socket_type::push};  
    sender.sender("1 10 20 UM Hello true");  

    return 0;
}
