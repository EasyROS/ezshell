#include "EZTools.hpp"

vector<string> EZTools::format(string buff, char ch) {
    if (buff[buff.length() - 1] != ch)
        buff += ch;
    string tmp = "";
    vector<string> strs;

    for (int i = 0; i < buff.length(); i++) {
        if (buff[i] == ch) {
            if (tmp.length() > 0) {
                strs.push_back(tmp);
                tmp = "";
            }
            continue;
        } else {
            tmp += buff[i];
        }
    }
    return strs;
}