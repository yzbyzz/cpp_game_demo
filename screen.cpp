#include "screen.h"

#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void Screen::init()
{
    renderIndex = 0;

    system("clear");

    for (int index = 0; index < SCREEN_BUFFER; index++)
    {
        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            int c = (index + i) % 26;
            for (int j = 0; j < SCREEN_WIDTH; j++)
            {
                c = (c + j) % 26;
                screen[0][i][j] = 'A' + c;
            }
        }
    }
}


void Screen::update()
{
    char tmp[SCREEN_WIDTH];

    for (int index = 0; index < SCREEN_BUFFER; index++)
    {
        strncpy(tmp, screen[index][0], SCREEN_WIDTH);

        for (int i = 1; i < SCREEN_HEIGHT; i++)
        {
            strncpy(screen[index][i - 1], screen[index][i], SCREEN_WIDTH);
        }

        strncpy(screen[index][SCREEN_HEIGHT - 1], tmp, SCREEN_WIDTH);
    }
}


void Screen::render()
{
   gotoxy(0, 0);

   for (int i = 0; i < SCREEN_HEIGHT; i++)
   {
       for (int j = 0; j < SCREEN_WIDTH; j++)
       {
           putchar(screen[renderIndex][i][j]);
       }
       putchar('\n');
   }
}

void Screen::gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}