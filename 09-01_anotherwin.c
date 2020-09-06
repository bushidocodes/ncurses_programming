#include <errno.h>
#include <ncurses.h>
#include <string.h>

int main()
{

    initscr();

    addstr("This is the standard screen\n");
    refresh();
    getch();

    /* Create a new window with the same size as stdscr */
    WINDOW *another = newwin(0, 0, 0, 0);
    if (another == NULL)
    {
        printw("newwin: %s", strerror(errno));
        wrefresh(stdscr);
        getch();
    }
    else
    {
        waddstr(another, "This is another window!");
        wrefresh(another);
        wgetch(another);
    }

    endwin();
    return 0;
}
