#include "EZTools.hpp"

vector<string> EZTools::format(string buff, char ch) {
    string tmp = "";
    vector<string> strs;

    for (int i = 0; i < buff.length(); i++) {
        if (buff[i] == ch) {
            if (tmp.length() > 0) {
                strs.push_back(tmp);
                tmp = "";
            }
            if(i == buff.length() - 1)
                strs.push_back(tmp);
            continue;
        } else {
            tmp += buff[i];
        }
    }
    if(tmp.length() > 0)
        strs.push_back(tmp);
    if(strs.size() == 0)
        strs.push_back("");
    return strs;
}

string EZTools::connect_string(vector<string> buffers, char ch) {
    string tmp = "";
    for (int i = 0; i < buffers.size(); i++) {
        tmp += buffers[i];
        if (i != buffers.size() - 1 && i != 0)
            tmp += ' ';
    }
    return tmp;
}