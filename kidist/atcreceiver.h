#include <zmq.hpp>
#include<string>
#include "atcsender.h"

class atcreceiver : public zmq::socket_t
{
private:
    zmq::context_t ctx;
    zmq::socket_t socket;
    atcsender sender;

public:

    std::string ip = "";
    atcreceiver(std::string url, zmq::context_t& context, zmq::socket_type type);
    void recieve();
    void sendResponse();
    ~atcreceiver();
};
