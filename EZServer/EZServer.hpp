#include <iostream>
#include <zmq.hpp>

using namespace std;

#ifndef _EZSERVER_HPP_
#define _EZSERVER_HPP_

bool power = true;
namespace EZServer {

    void startup() {
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REP);

        socket.bind("tcp://*:9999");

        char buffer[1024] = {0};

        while (power) {
            zmq_recv(socket, buffer, sizeof(buffer) - 1, 0);
            cout << "recv:" << buffer << endl;
            if (strcmp(buffer, "shutdown") == 0) {
                strcpy(buffer, "power is offed");
                zmq_send(socket, buffer, strlen(buffer) + 1, 0);
                break;
            }
            zmq_send(socket, buffer, strlen(buffer) + 1, 0);
        }
    }

    void poweroff(){
        power = false;
    }
}
#endif