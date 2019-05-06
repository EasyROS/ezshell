#ifndef EZSHELL_EZSOCKET_H
#define EZSHELL_EZSOCKET_H

#include <zmq.hpp>
#include <iostream>
#include <string>

using namespace std;

class EZSocket {
public:
    EZSocket();

    void send(string buffer);

    int port;
    void *s;
    void *context;
};


#endif //EZSHELL_EZSOCKET_H
