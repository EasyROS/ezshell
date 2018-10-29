#include "bindsys.hpp"
#include <iostream>
#include <vector>

using namespace std;

sys::sys() {}

sys::~sys() {}

void sys::setName(string name) {
    this->name = name;
}