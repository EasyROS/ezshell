#include "EZServer.hpp"

/// Debug [redefined] ----#ifndef #define #endif
#include "EZServer.hpp"

#include "../EZIO/directory.hpp"

#include <zmq.hpp>
#include <iostream>
#include <boost/thread.hpp>

using namespace std;

int main(int argc, char *argv[]) {
    boost::thread server_start(EZServer::startup);

    server_start.detach();

    EZServer::run();

    return 0;
}