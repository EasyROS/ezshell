#pragma once

#include <algorithm>
#include "EZIO.hpp"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) { if(p){delete(p); (p)=NULL;} }
#endif

class directory : public EZIO {
public:
    directory(string name);

    virtual ~directory();

    void Add(EZIO *ez);

private:
    directory();

};
