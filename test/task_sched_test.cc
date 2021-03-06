#include "co/log.h"
#include "co/time.h"
#include "co/thread.h"

void f() {
    COUT << "f(): " << now::str();
}

void g() {
    COUT << "g(): " << now::str();
}

int main(int argc, char** argv) {
    flag::init(argc, argv);
    log::init();

    COUT << "now: " << now::str();

    TaskSched s;
    s.run_in(f, 1);
    s.run_every(g, 3);
    s.run_daily(f, 23, 14, 0);

    while (1) {
        sleep::sec(1024);
    }

    return 0;
}
