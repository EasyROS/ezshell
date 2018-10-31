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
    while(true){
        C->getCommand();
    }

    return 0;
}
