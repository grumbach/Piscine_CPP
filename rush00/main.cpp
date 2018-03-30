#include "Engine.hpp"

int main(void) {
    Engine ngin;
    Engine ngin2 = Engine(ngin);

    ngin2.launch();
    ngin2.finish();
    return 0;
}