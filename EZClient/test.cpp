#include "EZClient.hpp"
#include "../EZIO/directory.hpp"

#include <iostream>
#include <zconf.h>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    EZClient *EZC = new EZClient();
    while (true) {
        string buff;
        cin >> buff;
        EZC->send(buff);
        EZC->recv();
        cout << EZC->getrecv() << endl;
        if (EZC->getrecv() == "exit")
            break;
        sleep(1);
    }
}