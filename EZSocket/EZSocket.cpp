#include <sstream>
#include "EZSocket.h"

EZSocket::EZSocket() {

    this->context = zmq_ctx_new();
    this->s = zmq_socket(this->context, ZMQ_REQ);

    stringstream ss;
    this->port = 9900;

    while (true)
        try {
            ss << this->port;
            zmq_bind(this->s, ("tcp://*:" + ss.str()).c_str());
            cout << "tcp://*:" + ss.str() << endl;
            break;
        } catch (zmq::error_t e) {
            //cout << port << e.what() << endl;
            this->port++;
        }
}

void EZSocket::send(string buff) {
    char buffer[1024] = {0};
    snprintf(buffer, sizeof(buffer), buff.c_str());
    zmq_send(s, buffer, strlen(buffer) + 1, 0);
}