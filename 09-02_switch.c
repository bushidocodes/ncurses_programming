#include <errno.h>
#include <ncurses.h>
#include <string.h>

int main()
{

    initscr();
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);

    /* Setup Second Window */
    WINDOW *second = newwin(0, 0, 0, 0);
    if (second == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(second, COLOR_PAIR(2));
    waddstr(second, "This is the second window\n");

    /* Setup Standard Screen */
    bkgd(COLOR_PAIR(1));
    addstr("This is the standard screen\n");
    addstr("Press Enter");

    /* Draw Standard Screen */
    refresh();
    getch();

    /* Draw Second Window */
    wrefresh(second);
    getch();

    endwin();
    return 0;
}
