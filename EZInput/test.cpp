#include "EZInput.hpp"

/// Debug [redefined] ----#ifndef #define #endif
//#include "EZInput.hpp"

#include "../EZIO/directory.hpp"
#include "ClientToServer.hpp"
#include <iostream>
#include <zconf.h>

/// Tune demo lib in this
//#include <curses.h>

using namespace std;

int main() {

    ClientToServer *CTS = new ClientToServer();
    CTS->get_list("ls");

    CTS->cmd("cmd");

    return 0;
}
