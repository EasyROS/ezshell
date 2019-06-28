#include "EZOutput.h"

/// Debug [redefined] ----#ifndef #define #endif
//#include "EZServer.hpp"

#include "../EZIO/directory.hpp"

#include <zmq.hpp>
#include <iostream>

/// Thread Server Test
//#include <boost/thread.hpp>

using namespace std;

/// Callback function
void *run(char *buff) {
    string str = buff;
    //cout << str << endl;
    EZServer::sendToClient(str);
}


int main(int argc, char *argv[]) {

    EZServer::startup(&run);

    return 0;
}
