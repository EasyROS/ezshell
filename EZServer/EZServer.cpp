#include "EZServer.h"

bool power = true;
directory *root;

void *soc;

void EZServer::init(directory *rp) {
    root = rp;
}

void EZServer::startup(void *run(char *buff)) {
    zmq::context_t context(15);
    zmq::socket_t socket(context, ZMQ_REP);

    char buffer[1024 * 512] = {0};
    socket.bind("tcp://*:9999");

    soc = socket;

    while (power) {
        zmq_recv(socket, buffer, sizeof(buffer) - 1, 0);
        run(buffer);
        usleep(1);
    }
}

void EZServer::sendToClient(string buff) {

    char buffer_[1024 * 512] = {0};

    strcpy(buffer_, buff.c_str());
    zmq_send(soc, buffer_, strlen(buffer_) + 1, 0);
}

void EZServer::poweroff() {
    power = false;
}