#include "file.hpp"
#include "directory.hpp"

int main() {

    EZIO *pRoot = new directory("root");
    EZIO *pTest = new directory("test");
    EZIO *pNode = new file("node");

    pTest->Add(pNode);
    pRoot->Add(pTest);

    cout << "Root\t\t\t" << pRoot->get_name() << endl
         << "Test\t\t\t" << pTest->get_name() << endl
         << "Root children\t" << pRoot->getChildren()[0]->get_name() << endl
         << "Test children\t" << pTest->getChildren()[0]->get_name() << endl
         << "Node parent\t\t" << pNode->getParent()->get_name() << endl
         << "Test parent\t\t" << pTest->getParent()->get_name() << endl;

    SAFE_DELETE(pRoot);

    return 0;
}