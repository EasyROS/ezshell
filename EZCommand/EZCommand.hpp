#include "../EZIO/file.hpp"
#include <iostream>
using namespace std;

#define _get_list '\01'
#define _change_dir '\02'
#define _run '\03'

class EZCommand {
public:
    EZCommand();

    ~EZCommand();
    
    EZIO *Command;
};