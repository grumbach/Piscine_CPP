#include "Engine.hpp"

int main(void) {
    Engine ngin;

    dprintf(2, "\n\n-------------------------------\n\n");
    if (!ngin.start())
        return (-1);
    ngin.launch();

    ngin.finish();
    return 0;
}