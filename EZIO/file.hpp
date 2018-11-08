#pragma once

#include "EZIO.hpp"

class file : public EZIO {
public:
    file(string name) : EZIO(name) {}

    virtual ~file() {}

    void Add(EZIO *ez) {}

private:
    file();
};

