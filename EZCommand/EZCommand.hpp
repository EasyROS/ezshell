#include "../EZIO/file.hpp"
#include <iostream>
using namespace std;

class Command {
public:
    Command(string name, EZIO *root);

    ~Command();

    void run();

    void tab();

    string command_dir;
    string command_str;
};