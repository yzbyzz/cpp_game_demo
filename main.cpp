#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

// x -->
// y |
//   |
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

const int WIDTH = 80;
const int HEIGHT = 30;
const int BUFFER = 2;

void initScreen(char screen[][HEIGHT][WIDTH])
{
    for (int index = 0; index < BUFFER; index++)
    {

    for (int i = 0; i < HEIGHT; i++)
    {
        int c = (index + i) % 26;
        for (int j = 0; j < WIDTH; j++)
        {
            c = (c + j) % 26;
            screen[0][i][j] = 'A' + c;
        }
    }

    }
}


void updateScreen(char screen[][HEIGHT][WIDTH])
{
    char tmp[WIDTH];

    for (int index = 0; index < BUFFER; index++)
    {
        strncpy(tmp, screen[index][0], WIDTH);


        for (int i = 1; i < HEIGHT; i++)
        {
            strncpy(screen[index][i-1], screen[index][i], WIDTH);
        }

        strncpy(screen[index][HEIGHT-1], tmp, WIDTH);
    }

}

int main()
{
    char screen[BUFFER][HEIGHT][WIDTH];

    initScreen(screen);

    system("clear");
    int screenIndex = 0;

    while (true)
    {
        gotoxy(0, 0);


        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
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
        usleep(16 * 1000);
    }
    puts("0123456789-1");
    puts("0123456789-2");
    puts("0123456789-3");
    puts("0123456789-4");
    puts("0123456789-5");

    putchar('A');


            gotoxy(0, 0);
            putchar('Z');
            gotoxy(0, 3);
            putchar('Y');
            gotoxy(1, 1);
            putchar('X');
            gotoxy(1, 2);
            putchar('W');


        sleep(1);
            gotoxy(100, 0);
            puts("end");


    return 0;
}