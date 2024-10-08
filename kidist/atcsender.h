#include <zmq.hpp>
class atcsender
{
private:
    zmq::context_t ctx;
    zmq::socket_t socket;
public:
    std::string ip = "";
    atcsender(std::string url, zmq::context_t& context, zmq::socket_type type);
    ~atcsender();
    void print(std::string msg);
    void send(std::string message);
};


