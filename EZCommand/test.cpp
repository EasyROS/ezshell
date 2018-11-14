#include "EZCommand.hpp"
#include "../EZIO/directory.hpp"

#include <iostream>

using namespace std;

int main() {
    EZIO *pRoot = new directory("root");
    Command *cd = new Command("cd", pRoot);
    Command *ls = new Command("ls", pRoot);

    cout << pRoot->getChildren().size() << endl;

    return 0;
}
