#ifndef EZSHELL_CLIENTSHELL_HPP
#define EZSHELL_CLIENTSHELL_HPP
#pragma once
#include "ClientToServer.hpp"

class ClientShell {
public:
    ClientShell();
    ~ClientShell();

    void success();
    void error();
    void info();
    void run();
    int getState();

private:
    int state = 3;
    string switch_demo(string buff);
};


#endif EZSHELL_CLIENTSHELL_HPP
