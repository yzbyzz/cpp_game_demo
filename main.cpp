#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

#include "config.h"


// x -->
// y |
//   |
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void initScreen(char screen[][SCREEN_HEIGHT][SCREEN_WIDTH])
{
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

void updateScreen(char screen[][SCREEN_HEIGHT][SCREEN_WIDTH])
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

int main()
{
    char screen[SCREEN_BUFFER][SCREEN_HEIGHT][SCREEN_WIDTH];

    initScreen(screen);

    system("clear");
    int screenIndex = 0;

    while (true)
    {
        gotoxy(0, 0);

        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            for (int j = 0; j < SCREEN_WIDTH; j++)
            {
                putchar(screen[screenIndex][i][j]);
            }
            putchar('\n');
        }

        // screenIndex++;
        // if (screenIndex >= BUFFER)
        // {
        //     screenIndex = 0;
        // }
        updateScreen(screen);
        usleep(MILLISECOND_IN_FRAME * 1000);
    }

    return 0;
}