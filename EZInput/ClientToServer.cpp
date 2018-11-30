//
// Created by dean on 18-11-26.
//

#include "ClientToServer.hpp"
#include "../EZCommand/EZCommand.hpp"

ClientToServer::ClientToServer() {
    this->Client = new EZClient();
}

ClientToServer::~ClientToServer() {

}

string ClientToServer::get_list(string dir) {
    this->Client->send(_get_list + dir);
    this->Client->recv();
    //cout << dir << this->Client->getrecv() << endl;
    return "";
}