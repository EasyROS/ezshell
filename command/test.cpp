#include "command.h"

#include <iostream>

using namespace std;

int main() {
    command *C = new command();
    int i = -1;
    while (i <= 5) {

        cout << C->setColorByStatus("颜色测试", i) << endl;
        i++;
    }
    string buff;

    while (true) {
        C->echo();
        //cout << buff << endl;
        C->run(C->getCommand());
//        if (buff.compare("ls") == 0)
//            cout << buff << endl;
//        if (buff.compare("cd") == 0)
//            cout << buff << endl;
//        if (buff.compare("rm") == 0)
//            cout << buff << endl;
//        if (buff.compare("mkdir") == 0)
//            cout << buff << endl;
    }
}
