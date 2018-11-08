#include <iostream>
#include <vector>

using namespace std;

class sys {
public:
    sys(string name) : name(name) {};

    virtual ~sys() {};

    sys *setName(string name);

    sys *toChild(string name);

    sys *searchChild(string name);

    virtual void bind(sys *s) = 0;

    sys *set_hidden() {
        this->hidden = true;
        return this;
    }

    sys *set_display() {
        this->hidden = false;
        return this;
    }

    sys *set_value(double val) {
        this->value = val;
        return this;
    }

    sys *set_info(string i) {
        this->info = i;
        return this;
    }

    vector<sys *> chirldren;
    sys *parent;

protected:
    string name;

private:
    sys();

    bool hidden;
    bool exec;
    double value;
    string info;

};