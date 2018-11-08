#pragma once

#include <algorithm>
#include "EZIO.hpp"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

class directory : public EZIO {
public:
    directory(string name) : EZIO(name) {}

    virtual ~directory() {
        while (!children.empty()) {
            vector<EZIO *>::iterator it = children.begin();
            SAFE_DELETE(*it);
            children.erase(it);
        }
    }

    void Add(EZIO *ez) {
        ez->setParent(this);
        children.push_back(ez);
    }

private:
    directory();

};
