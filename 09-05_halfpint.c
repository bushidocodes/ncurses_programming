#include <errno.h>
#include <ncurses.h>
#include <string.h>

int main()
{
    initscr();
    start_color();

    /* Configure Colors */
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    /* Setup TinyWindow */
    WINDOW *tiny = newwin(LINES / 2, COLS / 2, LINES / 4, COLS / 4);
    if (tiny == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }

    wbkgd(tiny, COLOR_PAIR(2));
    waddstr(tiny, "This is a tiny window\n");

    /* Setup Standard Screen */
    bkgd(COLOR_PAIR(1));
    addstr("This is the standard screen\n");
    addstr("Press Enter");

    /* Draw Standard Screen */
    refresh();
    getch();

    /* Draw Tiny Window */
    wrefresh(tiny);
    getch();

    /* Draw Standard Screen */
    touchwin(stdscr);
    refresh();
    getch();

    endwin();
    return 0;
}
