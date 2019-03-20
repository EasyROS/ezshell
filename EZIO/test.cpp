#include "file.hpp"
#include "directory.hpp"

class test : public file {
public:
    test(string name) : file(name) {}

    Json::Value run() {
        cout << "test_run" << endl;
    }
};

int main() {

    EZIO *pRoot = new directory("root");
    EZIO *pTest = new directory("test");
    //EZIO *pNode = new file("node");

    EZIO *T = new test("test_file");

    pTest->Add(T);
    pRoot->Add(pTest);

    cout << "Root\t\t\t" << pRoot->get_name() << endl
         << "Test\t\t\t" << pTest->get_name() << endl
         << "Root children\t" << pRoot->getChildren()[0]->get_name() << endl
         << "Test children\t" << pTest->getChildren()[0]->get_name() << endl
         //<< "Node parent\t\t" << pNode->getParent()->get_name() << endl
         << "Test parent\t\t" << pTest->getParent()->get_name() << endl;
    T->run();
    SAFE_DELETE(pRoot);

    return 0;
}
