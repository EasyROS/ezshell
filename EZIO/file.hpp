#pragma once

#include "EZIO.hpp"

class file : public EZIO {
public:
    file(string name);

    virtual ~file() {}

    virtual void run() = 0;

    void Add(EZIO *ez) {}

private:
    file();
};

