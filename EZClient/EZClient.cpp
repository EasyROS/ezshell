#include "EZClient.hpp"

EZClient::EZClient() {
    init();
}

EZClient::~EZClient() {
    zmq_close(s);
    zmq_ctx_destroy(context);
}

void EZClient::init() {
    this->context = zmq_ctx_new();
    this->s = zmq_socket(context, ZMQ_REQ);
    zmq_connect(this->s, "tcp://127.0.0.1:9999");
}

void EZClient::send(string buff) {
    snprintf(buffer, sizeof(buffer), buff.c_str());
    zmq_send(s, buffer, strlen(buffer) + 1, 0);
    strcpy(buffer, "");
}

void EZClient::recv() {
    zmq_recv(s, buffer, sizeof(buffer) - 1, 0);
}

string EZClient::getrecv() {
    string buff(this->buffer);
    return buff;
}