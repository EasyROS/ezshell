#include "EZOutput.h"

void out::listen(void * call(char *)) {
    EZServer::startup(call);
}