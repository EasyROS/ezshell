#include "../EZIO/file.hpp"
#include <iostream>
#include <json/json.h>
using namespace std;

class EZCommand {
public:
    EZCommand();

    ~EZCommand();
    
    EZIO *Command;

    string pwd;
    Json::Value data;
};