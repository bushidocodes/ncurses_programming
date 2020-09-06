#include <ncurses.h>

int main()
{
    initscr();

    int y = getmaxy(stdscr);
    int x = getmaxx(stdscr);
    int cmax = (x * y / 5);

    for (int c = 0; c < cmax; c++)
    {
        addstr("blah ");
    }
    refresh();
    getch();

    clear();
    refresh();
    getch();

    endwin();
    return 0;
}
