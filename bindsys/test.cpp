#include <iostream>
#include <unistd.h>
#include "bindsys.hpp"

using namespace std;

class root:public sys{
public:
    root(){
        char name[32];
        gethostname(name, sizeof(name));
        this->setName(name);
    }

    ~root(){}

    void bind(sys * s){
        this->chirldren.push_back(s);
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
    }

    bool exec() {
        return false;
    }
};

int main(int argc,char *argv[]){

//    cout << "test" << endl;
//    cout << argv[1] << endl;
    root *ROOT = new root();
    ROOT->bind(new test);
    cout << ROOT->name << endl;
    cout << ROOT->chirldren[0]->name << endl;

    return 0;
}