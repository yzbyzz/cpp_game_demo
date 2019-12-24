#ifndef ZZ_SCREEN
#define ZZ_SCREEN

#include "config.h"

class Screen
{
    public:
     void init();
     void update();
     void render();

    private:
        int renderIndex;
        char screen[SCREEN_BUFFER][SCREEN_HEIGHT][SCREEN_WIDTH];

     void gotoxy(int x, int y);
};

#endif