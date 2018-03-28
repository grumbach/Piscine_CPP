#include "Engine.hpp"

int main(void) {
    Engine ngin;

    if (!ngin.start())
        return (-1);
    ngin.launch();

    ngin.finish();
    return 0;
}