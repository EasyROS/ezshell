#include <iostream>
#include <zmq.hpp>

using namespace std;

class EZClient {
public:
    EZClient();

    ~EZClient();

    void init();

    void send(string buff);

    void recv();


    string getrecv();

private:
    void *context;
    void *s;
    char buffer[1024 * 512] = {0};
};