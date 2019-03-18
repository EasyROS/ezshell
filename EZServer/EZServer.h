#ifndef _EZSERVER_HPP_
#define _EZSERVER_HPP_

#include <iostream>
#include <zmq.hpp>
#include <zconf.h>
#include "../EZIO/directory.hpp"

using namespace std;


namespace EZServer {

    void init(directory *rp);

    void startup(void *run(char* buff)) ;

    void sendToClient(string buff) ;

    void poweroff() ;
}
#endif