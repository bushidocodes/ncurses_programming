#include <ncurses.h>
#include <string.h>

int main()
{
    initscr();

    for (int row = 0; row < LINES; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            addch('.');
        }
    }
    refresh();
    getch();

    /* Insert Three Rows */
    move(5, 0);
    insdelln(3);
    refresh();
    getch();

    /* Delete Five Rows */
    insdelln(-5);
    refresh();
    getch();

    endwin();
    return 0;
}
