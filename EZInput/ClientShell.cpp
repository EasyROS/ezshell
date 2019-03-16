//
// Created by dean on 18-11-30.
//
#pragma once
#include "ClientShell.hpp"
#include "../EZTools/EZTools.hpp"
#include "../EZCommand/EZCommand.hpp"
#include "ClientToServer.hpp"
#include "EZInput.hpp"

ClientShell::ClientShell() {}

ClientShell::~ClientShell() {}

void ClientShell::success() {
    this->state = 4;
}

void ClientShell::error() {
    this->state = -1;
}

void ClientShell::info() {
    this->state = 3;
}
int ClientShell::getState() {
    return this->state;
}
void ClientShell::run() {

    ClientToServer *CTS = new ClientToServer();

    while(true){

        string buff;
        cout << Input::setColorByStatus("➜ ", this->state);
        while(true){
            char c = getchar();
            if(c == '\n')
                break;
            buff += c;
        }

        string cmd = switch_demo(buff);
        CTS->talk(cmd);

        if(buff == "shutdown")
            break;
    }
    delete CTS;
}

string ClientShell::switch_demo(string buff) {
    vector<string> cmd = EZTools::format(buff, ' ');
    string tmp;
    cout << (cmd[0] == "cd") << endl;
    if (cmd[0] == "ls"){
        this->info();
        cmd[0] = _get_list;
    }
    else if (cmd[0] == "cd"){
        this->success();
        cmd[0] = _change_dir;
    }
    else{
        this->error();
        tmp = _run;
        cmd.insert(cmd.begin(), tmp);
    }

    return EZTools::connect_string(cmd, ' ');
}
