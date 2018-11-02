#include "bindsys.hpp"
#include <iostream>
#include <vector>

using namespace std;

sys::sys() {}

sys::~sys() {}

void sys::setName(string name) {
    this->name = name;
}

sys *sys::toChild(string name) {
    if(name == ".." || name == "../"){
        return this->parent;
    }
    int i;
    for (i = 0; i < this->chirldren.size(); i++) {
        if (name == this->chirldren[i]->name)
            return this->chirldren[i];
    }
    if (this->chirldren.size() == i)
        throw "Not found such node !";
}

sys *sys::searchChild(string name) {
    int i, j = 0;
    for (i = 0; i < this->chirldren.size(); i++) {
        while (j <= name.length()) {
            if(j == name.length())
                return this->chirldren[i];
            else if (name[j] == this->chirldren[i]->name[j])
                j++;
            else
                break;
        }
    }
    if (this->chirldren.size() == i)
        throw "Not found end node !";
}