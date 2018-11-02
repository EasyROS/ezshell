#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include "command.h"

#include <regex.h>
#include <cstdlib>

class root : public sys {
public:
    root() {
        char name[32];
        gethostname(name, sizeof(name));
        this->setName(name);
    }

    ~root() {}

    void bind(sys *s) {
        this->chirldren.push_back(s);
        s->parent = this;
    }

    bool exec() {
        return false;
    }
};

class test : public root {
public:
    test() {
        this->setName("test");
    }

    ~test() {}

    void bind(sys *s) {
        this->chirldren.push_back(s);
        s->parent = this;
    }

    bool exec() {
        return false;
    }
};

command::command() {
    this->node = new root();
    this->node->bind(new test);
    this->dir = "/";
}

command::~command() {

}

string command::setColorByStatus(string buff, int state) {
    switch (state) {
        case -1:
            return "\033[31;1m" + buff + "\033[0m";
        case 0:
            return "\033[35;1m" + buff + "\033[0m";
        case 1:
            return "\033[37;1m" + buff + "\033[0m";
        case 2:
            return "\033[34;1m" + buff + "\033[0m";
        case 3:
            return "\033[32;1m" + buff + "\033[0m";
        case 4:
            return "\033[33;1m" + buff + "\033[0m";
        default:
            return setColorByStatus("Not found the STATE!", -1);
    }
}

string command::getCommand() {
    struct termios oldt;
    struct termios newt;
    int ch;
    string buff;
    buff.clear();
    while (1) {

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if (ch != 10) {
            switch (ch) {
                case 9:
                    buff = this->findCommand(buff);
                    break;
                case 27:
                    for (int i = 0; i < buff.length(); i++)
                        printf("\b \b");
                    buff.clear();
                    break;
                case 127:
                    if (buff.length() > 0) {
                        printf("\b \b");
                        buff = buff.substr(0, buff.length() - 1);
                    }
                    break;
                case 91:
                    switch (getchar()){
                        case 65:
                            cout << "up";
                    }
                    break;
                default:
                    buff += ch;
                    printf("%c", ch);
            }
        } else {
            printf("%c", ch);
            return buff;
        }
    }
}

string command::findCommand(string commstr) {
    string buff;
    sys *N = this->node;
    vector<string> com = format_space(commstr);
    vector<string> dirs;
    if (com.size() > 1) {
        //cout << endl << "com:" << com.back().data() << endl;
        dirs = format_dir(com.back().data());
        //cout << endl << "dir:" << dirs.back().data() << endl;
        for (int i = 0; i < dirs.size(); i++) {
            if (i == dirs.size() - 1) {
                try {
                    N = N->searchChild(dirs[i]);
                    if(commstr[commstr.length() - 1] == '/'){
                        commstr = commstr.substr(0, commstr.length() - 1);
                        printf("\b \b");
                    }
                    commstr = commstr.substr(0, commstr.length() - dirs[i].length()) + N->name + "/";
                    cout << N->name.substr(dirs[i].length(), N->name.length()) + "/";

                } catch (char const *err) {
                    this->echoError(err);
                    cout << commstr;
                }
            } else
                try {
                    printf("   %s",dirs[i].c_str());
                    N = N->toChild(dirs[i]);
                    //printf("   %s   %s", dirs[i].c_str(), this->node->name.c_str());
                } catch (char const *err) {
                    this->echoError(err);
                    cout << commstr;
                    break;
                }
            //cout << endl << dirs[i];
        }
        //cout << dirs.size();
        //printf("%s", com.back().data());
    }
    return commstr;
}

vector<string> command::format_space(string buff) {
    if(buff[buff.length() - 1] != ' ')
        buff += " ";
    string tmp = "";
    vector<string> strs;

    for (int i = 0; i < buff.length(); i++) {
        if(buff[i] == ' '){
            if(tmp.length() > 0){
                strs.push_back(tmp);
                tmp = "";
            }
            continue;
        }else{
            tmp += buff[i];
        }
    }
    return strs;
}

vector<string> command::format_dir(string buff) {
    if(buff[buff.length() - 1] != '/')
        buff += "/";

    string tmp = "";
    vector<string> strs;

    for (int i = 0; i < buff.length(); i++) {
        if(buff[i] == '/'){
            if(tmp.length() > 0){
                strs.push_back(tmp);
                tmp = "";
            }
            continue;
        }else{
            tmp += buff[i];
        }
    }
    return strs;
}

void command::run(string commstr) {
    vector<string>commands = format_space(commstr);
    //if(commands[1].length() > 0)
        //cout << commands.size() << commstr << commands[1].length()<< endl;
    if(commands.size() == 1)
        if(commands[0] == "ls")
            ls("");
        else if(commands[0] == "cd")
            cd("/");
        else if(commands[0] == "exit"){
            cout << "Exited!" << endl;
            exit(0);
        }
        else{
            this->echoError("Command not found");
            run(getCommand());
        }
    else if(commands.size() == 2)
        if(commands[0] == "ls"){
            ls(commands[1]);
        } else if(commands[0] == "cd")
            cd(commands[1]);
        else if(commands[0] == "rm")
            rm(commands[1]);
        else if(commands[1] == "mkdir")
            mkdir(commands[1]);
        else{
            this->echoError("Command not found");
            run(getCommand());
        }
    else{
        this->echoError("Command option too much");
        run(getCommand());
    }

}

void command::ls(string buff) {
    if(buff.size() == 0){
        for(int i = 0; i< this->node->chirldren.size(); i++){
            cout << this->node->chirldren[i]->name << "\t" ;
        }
        cout << endl;
    }else{
        cout << buff << endl;
    }
//    cout << buff.size() << endl;
//    cout <<  buff.data() <<endl;
}

void command::cd(string buff) {
    cout << "cd:" + buff <<endl;
}

void command::rm(string buff) {
    cout << "rm:" + buff <<endl;
}

void command::mkdir(string buff) {
    cout << "mkdir:" + buff <<endl;
}

void command::echoError(string err) {
    cout << endl << this->setColorByStatus(err, -1) << endl << this->setColorByStatus("✘ ", -1)
         << this->setColorByStatus(this->dir + " ", 2);
}

void command::echo() {
    cout << this->setColorByStatus("➜ ", 3) << this->setColorByStatus(this->dir + " ", 2);
}