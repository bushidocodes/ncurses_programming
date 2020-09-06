#include <ncurses.h>

int main()
{
    initscr();

    /* Define subwindow inside of the border */
    WINDOW *sub = derwin(stdscr, LINES - 2, COLS - 2, 1, 1);
    if (sub == NULL)
    {
        endwin();
        puts("Unable to create subwindow");
        return 1;
    }

    /* Add a Border to the main window */
    box(stdscr, 0, 0);

    /* Write text to the subwindow */
    addstr("I'm writing text to the standard screen.\n");

    refresh();
    getch();

    wclear(sub);
    wrefresh(sub);
    getch();

    endwin();
    return 0;
}
