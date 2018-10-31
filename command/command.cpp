#include <cstdio>
#include <cstdlib>
#include "command.h"

command::command() {

}

command::~command() {

}

string command::setColorByStatus(string buff, int state) {
    switch (state){
        case -1:
            return "\033[31;1m " + buff + " \033[0m";
        case 0:
            return "\033[35;1m " + buff + " \033[0m";
        case 1:
            return "\033[37;1m " + buff + " \033[0m";
        case 2:
            return "\033[34;1m " + buff + " \033[0m";
        case 3:
            return "\033[32;1m " + buff + " \033[0m";
        case 4:
            return "\033[33;1m " + buff + " \033[0m";
        default:
            return setColorByStatus("Not found the STATE!", -1);
    }
}

string command::getCommand() {
    char buff;
    system("stty -echo");
    while(1){
        cin.get(buff);
        if(buff == 10){
            printf("%c",buff);
            system("stty -echo");
            return "command test";
        }
        printf("%d",buff);
    }
}