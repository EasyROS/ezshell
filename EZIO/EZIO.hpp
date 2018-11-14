#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class EZIO {
public:
    EZIO();
    EZIO(string name) : name(name) {};

    virtual ~EZIO() {};

    virtual void Add(EZIO *ez) = 0;
    virtual void run() = 0;

    vector<EZIO *> getChildren() {
        return this->children;
    }

    void setParent(EZIO *ez) {
        this->parent = ez;
    }

    EZIO *getParent() {
        return this->parent;
    }

    EZIO *toChild(string name) {
        int i = 0;
        for (; i < children.size(); i++) {
            if (children[i]->get_name() == name)
                break;
        }

        if (i != children.size()) {
            return children[i];
        } else {
            throw "No child";
        }
    }

    EZIO *searchChild(string name) {

    }

    EZIO *set_exec() {
        this->exec = true;
    }

    EZIO *set_not_exec() {
        this->exec = false;
    }

    EZIO *set_global() {
        this->global = true;
    }

    EZIO *set_not_global() {
        this->global = false;
    }

    EZIO *set_hidden() {
        this->hidden = true;
        return this;
    }

    EZIO *set_display() {
        this->hidden = false;
        return this;
    }


    string get_name() {
        return this->name;
    }

    const map<string, string> &getInfo_list() const {
        return info_list;
    }

    void setInfo_list(const map<string, string> &info_list) {
        this->info_list = info_list;
    }

protected:
    string name;
    vector<EZIO *> children;
    EZIO *parent;

private:

    bool global;
    bool hidden;
    bool exec;

    map<string, string> info_list;
};