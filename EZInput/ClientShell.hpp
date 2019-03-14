#ifndef EZSHELL_CLIENTSHELL_HPP
#define EZSHELL_CLIENTSHELL_HPP
#pragma once
#include "ClientToServer.hpp"

class ClientShell {
public:
    ClientShell();
    ~ClientShell();

    void run();

private:
    int state = 3;
    void success();
    void error();
    void info();
    string switch_demo(string buff);
};


#endif EZSHELL_CLIENTSHELL_HPP
