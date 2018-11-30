//
// Created by dean on 18-11-30.
//

#include "ClientShell.hpp"
#include "../EZTools/EZTools.hpp"
#include "../EZCommand/EZCommand.hpp"
#include "ClientToServer.hpp"

ClientShell::ClientShell() {}

ClientShell::~ClientShell() {}

void ClientShell::run() {

    ClientToServer *CTS = new ClientToServer();

    while(true){

        string buff;
        cin >> buff;
        string cmd = switch_demo(buff);

        CTS->talk(cmd);

        if(buff == "shutdown")
            break;
    }
}

string ClientShell::switch_demo(string buff) {
    vector<string> cmd = EZTools::format(buff, ' ');
    string tmp;
    if (cmd[0] == "ls")
        cmd[0] = _get_list;
    else if (cmd[0] == "cd")
        cmd[0] = _change_dir;
    else{
        tmp = _run;
        cmd.insert(cmd.begin(), tmp);
    }

    return EZTools::connect_string(cmd, ' ');
}
