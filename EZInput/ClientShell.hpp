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
    int getState();

private:
    int state = 3;
};


#endif EZSHELL_CLIENTSHELL_HPP
