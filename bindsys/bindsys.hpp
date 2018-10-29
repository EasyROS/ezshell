#include <iostream>
#include <vector>

#define Executable false;

#define Error = -1;
#define Stoped = 0;
#define Started = 1;
#define Running = 2;

using namespace std;

class sys {
public:
    sys();

    ~sys();

    void setName(string name);

    virtual void bind(sys *s) = 0;

    virtual bool exec() = 0;

    double value;
    string info;
    string name;
    vector<sys *> chirldren;
    sys *parent;
};