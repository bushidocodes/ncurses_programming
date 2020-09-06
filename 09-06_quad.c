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
    init_pair(3, COLOR_WHITE, COLOR_CYAN);
    init_pair(4, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(5, COLOR_WHITE, COLOR_GREEN);

    /* Setup First */
    WINDOW *first = newwin(LINES / 2, COLS / 2, 0, 0);
    if (first == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(first, COLOR_PAIR(2));
    waddstr(first, "This is a the first window\n");

    /* Setup Second */
    WINDOW *second = newwin(LINES / 2, COLS / 2, 0, COLS / 2);
    if (second == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(second, COLOR_PAIR(3));
    waddstr(second, "This is a the second window\n");

    /* Setup Third */
    WINDOW *third = newwin(LINES / 2, COLS / 2, LINES / 2, 0);
    if (third == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(third, COLOR_PAIR(4));
    waddstr(third, "This is a the third window\n");

    /* Setup Fourth */
    WINDOW *fourth = newwin(LINES / 2, COLS / 2, LINES / 2, COLS / 2);
    if (fourth == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(fourth, COLOR_PAIR(5));
    waddstr(fourth, "This is a the fourth window\n");

    /* Setup Standard Screen */
    bkgd(COLOR_PAIR(1));
    addstr("This is the standard screen\n");
    addstr("Press Enter");

    /* Draw Standard Screen */
    refresh();
    getch();

    /* Draw Tiny Window */
    wrefresh(first);
    refresh();
    getch();
    wrefresh(second);
    refresh();
    getch();
    wrefresh(third);
    refresh();
    getch();
    wrefresh(fourth);
    refresh();
    getch();

    /* Draw Standard Screen */
    touchwin(stdscr);
    refresh();
    getch();

    endwin();
    return 0;
}
