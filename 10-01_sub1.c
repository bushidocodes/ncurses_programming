#include <ncurses.h>

int main()
{
    initscr();

    /* Define subwindow inside of the border */
    WINDOW *sub = subwin(stdscr, LINES - 2, COLS - 2, 1, 1);
    if (sub == NULL)
    {
        endwin();
        puts("Unable to create subwindow");
        return 1;
    }

    /* Add a Border to the main window */
    box(stdscr, 0, 0);

    /* Write text to the subwindow */
    waddstr(sub, "I'm in a subwindow.\n");

    refresh();
    getch();

    endwin();
    return 0;
}
