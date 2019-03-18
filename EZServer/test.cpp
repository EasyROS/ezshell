#include "EZServer.h"

/// Debug [redefined] ----#ifndef #define #endif
//#include "EZServer.hpp"

#include "../EZIO/directory.hpp"

#include <zmq.hpp>
#include <iostream>
#include "../EZCommand/EZCommand.hpp"

/// Thread Server Test
//#include <boost/thread.hpp>

using namespace std;

/// Callback function
void *run(char *buff) {
    if (strcmp(buff, "shutdown") == 0)
        EZServer::poweroff();
    EZServer::sendToClient(buff);
}


int main(int argc, char *argv[]) {

    EZServer::startup(&run);

    return 0;
}
