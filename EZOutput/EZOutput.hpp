#include <iostream>
#include <zmq.hpp>
#include <zconf.h>
#include "../EZServer/EZServer.hpp"
#include "../EZCommand/EZCommand.hpp"
#include "../EZIO/directory.hpp"

using namespace std;

#ifndef _EZOUTPUT_HPP_
#define _EZOUTPUT_HPP_



namespace out {

    void listen(void * call(char *)){
        EZServer::startup(call);
    }
}
#endif