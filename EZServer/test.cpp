#include "EZCommand.hpp"
#include "../EZIO/directory.hpp"

#include <iostream>

using namespace std;

namespace ROOT {
    EZIO *pRoot = new directory("root");
}

class test_command : public file {
public:
    test_command(string name) : file(name) {}

    void run() {
        cout << "test_run" << endl;
    }
};

class test : public EZCommand {
public:
    test() {
        EZIO *T = new test_command("test");

        ROOT::pRoot->Add(T);
        T->set_global()->set_exec()->set_hidden();
    }

    ~test() {

    }
};

namespace EZC {
    EZCommand *Test = new test();
}

int main() {

    cout << ROOT::pRoot->getChildren()[0]->get_name() << endl;

    ROOT::pRoot->getChildren()[0]->run();

    return 0;
}
