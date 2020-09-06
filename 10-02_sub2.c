#include <ncurses.h>

int main()
{
    initscr();

    /* Define subwindow inside of the border */
    WINDOW *sub = subwin(stdscr, LINES / 2, COLS / 2, LINES / 4, COLS / 4);
    if (sub == NULL)
    {
        endwin();
        puts("Unable to create subwindow");
        return 1;
    }

    /* Write text to the subwindow */
    box(stdscr, 0, 0);
    wmove(stdscr, 1, 1);
    addstr("I'm the main window.");

    box(sub, 0, 0);
    wmove(sub, 1, 1);
    waddstr(sub, "I'm in a subwindow.");

    refresh();
    getch();

    endwin();
    return 0;
}
