#include <iostream>
#include <vector>

#define Error = -1;
#define Stoped = 0;
#define Started = 1;
#define Running = 2;
#define Executable 3;
#define Info 4;

using namespace std;
class command {
public:
    command();
    ~command();

    string setColorByStatus(string buff,int state);

    string getCommand();
};
