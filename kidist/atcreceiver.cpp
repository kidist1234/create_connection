#include<iostream>
#include"atcreceiver.h"
#include<string>
#include <zmq.hpp>
atcreceiver::atcreceiver(std::string url, zmq::context_t& context, zmq::socket_type type)
 : socket(context, type),sender{"tcp://*:5558", context, zmq::socket_type::push}{
    ip = url;
     socket.connect(ip);
          
}
void atcreceiver ::recieve()
{
     zmq::message_t zmq_message;
        std::optional<long unsigned int> s = socket.recv(zmq_message, zmq::recv_flags::none);
        std::string message(static_cast<char*>(zmq_message.data()), zmq_message.size());

        std::istringstream iss(message);
        std::vector<std::string> components;
        std::string component;
         std::cout << "Received: " << message << std::endl;

        while (std::getline(iss, component, ' ')) {
            components.push_back(component);
        }
        std::string id;
        std::string response_required;
        if (components.size() >= 5) {
            id = components[0];
            std::string min = components[1];
            std::string mrn = components[2];
            std::string type = components[3];
            std::string msg = components[4];
            response_required = components[5];

            
        } else {
            std::cerr << "Error: Insufficient components in the message." << std::endl;
        }


             if (response_required == "true") {
                std::string response_message = "Response to " + id + ": Acknowledged.";
                sender.send(response_message);
            }
    }
atcreceiver::~atcreceiver() 
{
    std::cout << "In receiver Socket Destructor"<<std::endl;
}

int main(){
    zmq::context_t ctx(1);
    atcreceiver receiver{"tcp://localhost:5557", ctx, zmq::socket_type::pull};
    receiver.recieve();
}