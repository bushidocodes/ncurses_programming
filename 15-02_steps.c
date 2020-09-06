#include <ncurses.h>

int main()
{
    initscr();

    int maxx = getmaxx(stdscr);
    int maxy = getmaxy(stdscr);

    int x, y;
    for (y = x = 0; y < maxy; y++, x += 2)
    {
        move(y, x);
        hline(0, maxx - x);
        vline(0, maxy - y);
    }

    refresh();
    getch();

    endwin();
    return 0;
}
