#ifndef EZSHELL_CLIENTTOSERVER_HPP
#define EZSHELL_CLIENTTOSERVER_HPP

#include "../EZClient/EZClient.hpp"
#include "../EZIO/EZIO.hpp"

class ClientToServer {
public:
    ClientToServer();

    ~ClientToServer();

    string talk(string str);

    void send(string str);

    string recv();

    EZClient *Client;
};


#endif //EZSHELL_CLIENTTOSERVER_HPP
