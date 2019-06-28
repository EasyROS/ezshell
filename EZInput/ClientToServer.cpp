//
// Created by dean on 18-11-26.
//

#include "ClientToServer.hpp"
#include "../EZCommand/EZCommand.hpp"

ClientToServer::ClientToServer() {
    this->Client = new EZClient();
}

ClientToServer::~ClientToServer() {
    delete (this->Client);
    delete this;
}

string ClientToServer::talk(string str) {
    this->Client->send(str);
    this->Client->recv();
    return this->Client->getrecv();
}

void ClientToServer::send(string str) {
    this->Client->send(str);
}

string ClientToServer::recv() {
    this->Client->recv();
    return this->Client->getrecv();
}