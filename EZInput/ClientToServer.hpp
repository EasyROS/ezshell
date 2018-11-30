#ifndef EZSHELL_CLIENTTOSERVER_HPP
#define EZSHELL_CLIENTTOSERVER_HPP

#include "../EZClient/EZClient.hpp"
#include "../EZIO/EZIO.hpp"

class ClientToServer {
public:
    ClientToServer();

    ~ClientToServer();

    string get_list(string dir);

    string cmd(string str);

    EZClient *Client;
};


#endif //EZSHELL_CLIENTTOSERVER_HPP
