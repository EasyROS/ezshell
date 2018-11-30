#include "EZServer.hpp"

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
    switch (buff[0]){
        case _get_list:
            //cout << "getlist" << endl;
            for(int i = 0;buff[i] = buff[i + 1];i++);
            cout << buff << endl;
            break;
        case _run:
            //cout << "run" << endl;
            for(int i = 0;buff[i] = buff[i + 1];i++);
            cout << buff << endl;
            break;
        default:
            cout << buff << endl;
    }
    EZServer::sendToClient(buff);
}


int main(int argc, char *argv[]) {

    EZServer::startup(&run);

    return 0;
}
