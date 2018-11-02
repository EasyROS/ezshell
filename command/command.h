#include <iostream>
#include <vector>
#include <map>
#include "../bindsys/bindsys.hpp"

#define Error = -1;
#define Stoped = 0;
#define Started = 1;
#define Running = 2;
#define Executable 3;
#define Info 4;

using namespace std;

class command {
public:
    command();

    ~command();

    string setColorByStatus(string buff, int state);

    string getCommand();

    string findCommand(string commstr);

    string dir;

    vector<string> format_space(string buff);

    vector<string> format_dir(string buff);

    void run(string commstr);

    void ls(string buff);

    void cd(string buff);

    void mkdir(string buff);

    void rm(string buff);

    void echoError(string err);

    void echo();

    sys *node;
};
