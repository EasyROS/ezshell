#include "EZServer.hpp"

/// Debug [redefined] ----#ifndef #define #endif
#include "EZServer.hpp"

#include "../EZIO/directory.hpp"

#include <zmq.hpp>
#include <iostream>
#include <boost/thread.hpp>

using namespace std;

void run(){
    //cout << EZServer::getRecv() << endl;
    if(EZServer::getRecv() == "shutdown"){
        EZServer::sendToClient("power is offed");

        sleep(1);
        EZServer::poweroff();
    }
}

int main(int argc, char *argv[]) {
    boost::thread server_start(EZServer::startup);

    server_start.detach();

    return 0;
}