#include <cstdio>
#include <unistd.h>

#include "config.h"
#include "screen.h"


int main()
{
    Screen screen;
    screen.init();


    while (true)
    {
        screen.render();
        screen.update();
        usleep(MILLISECOND_IN_FRAME * 1000);
    }

    return 0;
}