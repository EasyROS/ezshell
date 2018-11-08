#include "directory.hpp"

directory::directory(string name) : EZIO(name) {}

directory::~directory() {
    while (!children.empty()) {
        vector<EZIO *>::iterator it = children.begin();
        SAFE_DELETE(*it);
        children.erase(it);
    }
}

void directory::Add(EZIO *ez) {
    ez->setParent(this);
    children.push_back(ez);
}