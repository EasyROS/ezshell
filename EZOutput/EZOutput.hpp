#include <iostream>
#include <zmq.hpp>
#include <zconf.h>
#include "../EZIO/directory.hpp"

using namespace std;

#ifndef _EZSERVER_HPP_
#define _EZSERVER_HPP_

bool power = true;
directory *root;

void *soc;

namespace EZServer {

    void init(directory *rp) {
        root = rp;
    }

    void startup(void *run(char* buff)) {
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REP);

        char buffer[1024] = {0};
        socket.bind("tcp://*:9999");

        soc = socket;

        while (power) {
            zmq_recv(socket, buffer, sizeof(buffer) - 1, 0);
            run(buffer);
            usleep(1);
        }
    }

    void sendToClient(string buff) {

        char buffer_[1024] = {0};

        strcpy(buffer_, buff.c_str());
        zmq_send(soc, buffer_, strlen(buffer_) + 1, 0);
    }

    void poweroff() {
        power = false;
    }
}
#endif