#include "EZSocket.h"

/// Debug [redefined] ----#ifndef #define #endif
//#include "EZServer.hpp"

#include "../EZIO/directory.hpp"

#include <zmq.hpp>
#include <iostream>
#include "../EZCommand/EZCommand.hpp"

/// Thread Server Test
//#include <boost/thread.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    string buff = "test";
    char buffer[1024] = {0};
    EZSocket *soc = new EZSocket();
    snprintf(buffer, sizeof(buffer), buff.c_str());
    while (true) {
        //cout << soc->port << endl;
        zmq_recv(soc->s, buffer, sizeof(buffer) - 1, 0);
        cout << buffer << endl;
        soc->send(buffer);
        strcpy(buffer, "");
        zmq_sleep(1);
    }
    return 0;
}
