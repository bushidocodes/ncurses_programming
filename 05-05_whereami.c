#include <ncurses.h>

int main()
{

    initscr();

    addstr("Type some text; '~' to end\n");
    refresh();

    char ch = '\0';
    while ((ch = getch()) != '~')
        ;

    printw("\n\nThe cursor was at position %d %d when you stopped typing.", getcury(stdscr), getcurx(stdscr));

    refresh();
    getch();

    endwin();
    return 0;
}
