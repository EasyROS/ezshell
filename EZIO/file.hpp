#pragma once

#include "EZIO.hpp"
#include <json/json.h>

class file : public EZIO {
public:
    file(string name);

    virtual ~file() {}

    virtual Json::Value run() = 0;

    void Add(EZIO *ez) {}

private:
    file();
};

