#include <ncurses.h>

int main()
{
    initscr();

    scrollok(stdscr, true);

    for (int i = 0; i < LINES; i++)
    {
        mvprintw(i, 0, "%2d", i);
    }

    refresh();
    getch();

    scroll(stdscr);
    refresh();
    getch();

    endwin();
    return 0;
}
