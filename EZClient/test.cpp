#include "EZClient.hpp"
#include "../EZIO/directory.hpp"

#include <iostream>
#include <zconf.h>

using namespace std;

int main(int argc, char *argv[]) {
    EZClient *EZC = new EZClient();
    while(1) {
        string buff;
        cin >> buff;
        EZC->send(buff);
        EZC->recv();
        cout << EZC->getrecv() << endl;
        if(EZC->getrecv() == "exit")
            break;
        sleep(1);
    }
}