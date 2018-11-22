#include "../EZIO/file.hpp"
#include <iostream>
using namespace std;

class EZCommand {
public:
    EZCommand();

    ~EZCommand();
    
    EZIO *Command;
};