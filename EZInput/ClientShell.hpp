#ifndef EZSHELL_CLIENTSHELL_HPP
#define EZSHELL_CLIENTSHELL_HPP

#include "ClientToServer.hpp"

class ClientShell {
public:
    ClientShell();
    ~ClientShell();

    void run();

private:
    string switch_demo(string buff);
};


#endif //EZSHELL_CLIENTSHELL_HPP
