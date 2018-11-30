#include "EZInput.hpp"

/// Debug [redefined] ----#ifndef #define #endif
//#include "EZInput.hpp"

#include "../EZIO/directory.hpp"
#include "ClientToServer.hpp"
#include <iostream>
#include <zconf.h>

using namespace std;

int main() {

    ClientToServer *CTS = new ClientToServer();
    CTS->get_list("test");

    return 0;
}
