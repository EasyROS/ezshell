#pragma once

#include <iostream>
#include <vector>
#include <json/json.h>
#include <map>

using namespace std;

class EZIO {
public:
    EZIO();

    EZIO(string name) : name(name), view(false) {};

    virtual ~EZIO() {};

    virtual void Add(EZIO *ez) = 0;

    virtual Json::Value run() = 0;

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
        if (name == "..") {
            try {
                //cout << this->parent->get_name() << endl;
                if (!this->parent->get_name().empty())
                    return this->parent;
            } catch (std::bad_alloc e) {
                throw "404";
            }

        } else if (name == "." || name == "")
            return this;
        else {
            int i = 0;
            for (; i < this->getChildren().size(); i++) {
                if (this->getChildren()[i]->get_name() == name)
                    return this->getChildren()[i];
            }
            if (i == this->getChildren().size())
                throw "404";
        }
    }

    vector<string> getPWD() {
        EZIO *T = this;
        vector<string> pwdl;
        while (true) {
            try {
                if (T->get_name() != "root") {
                    pwdl.insert(pwdl.begin(), T->get_name());
                    T = T->parent;
                } else
                    break;
            } catch (std::bad_alloc error) {
                break;
            }

        }
        return pwdl;
    }

    EZIO *set_exec() {
        this->exec = true;
        return this;
    }

    EZIO *set_not_exec() {
        this->exec = false;
        return this;
    }

    EZIO *set_not_view() {
        this->view = false;
        return this;
    }

    EZIO *set_global() {
        this->global = true;
        return this;
    }

    EZIO *set_not_global() {
        this->global = false;
        return this;
    }

    bool _global() {
        return this->global;
    }

    bool _hidden() {
        return this->hidden;
    }

    bool _exec() {
        return this->exec;
    }

    bool _view() {
        return this->view;
    }

    bool _dir() {
        return this->dir;
    }

    bool _file() {
        return this->file;
    }

    EZIO *set_dir() {
        this->dir = true;
        this->file = false;
        return this;
    }

    EZIO *set_file() {
        this->file = true;
        this->dir = false;
        return this;
    }

    EZIO *set_hidden() {
        this->hidden = true;
        return this;
    }

    EZIO *set_view() {
        this->view = true;
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

    string pwd;
    string cmd;
    string btn;
    Json::Value res;

protected:
    string name;
    vector<EZIO *> children;
    EZIO *parent;

private:
    bool global;
    bool hidden;
    bool exec;
    bool file;
    bool dir;
    bool view;

    map<string, string> info_list;
};