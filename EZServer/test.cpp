#include "EZServer.hpp"

/// Debug [redefined] ----#ifndef #define #endif
#include "EZServer.hpp"

#include "../EZIO/directory.hpp"

#include <zmq.hpp>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    EZServer::startup();

    return 0;
}