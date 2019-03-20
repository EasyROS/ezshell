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

    Json::Value run() {
        cout << "test_run" << endl;
    }
};

class test : public EZCommand {
public:
    test() {
        this->Command = new test_command("test");

        ROOT::pRoot->Add(this->Command);
        this->Command->set_global()->set_exec()->set_hidden();
    }

    ~test() {

    }

};

namespace EZC {
    EZCommand *Test = new test();
}

int main() {

    cout << ROOT::pRoot->getChildren()[0]->get_name() << ROOT::pRoot->getChildren()[0]->_exec()
         << ROOT::pRoot->getChildren()[0]->_hidden() << ROOT::pRoot->getChildren()[0]->_global() << endl;

    ROOT::pRoot->getChildren()[0]->run();

    return 0;
}
