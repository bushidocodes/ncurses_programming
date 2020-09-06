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
    box(first, 0, 0);
    mvwaddstr(first, 1, 1, "This is a the first window");

    /* Setup Second */
    WINDOW *second = newwin(LINES / 2, COLS / 2, 0, COLS / 2);
    if (second == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(second, COLOR_PAIR(3));
    box(second, 0, 0);
    mvwaddstr(second, 1, 1, "This is a the second window");

    /* Setup Third */
    WINDOW *third = newwin(LINES / 2, COLS / 2, LINES / 2, 0);
    if (third == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(third, COLOR_PAIR(4));
    box(third, 0, 0);
    mvwaddstr(third, 1, 1, "This is a the third window");

    /* Setup Fourth */
    WINDOW *fourth = newwin(LINES / 2, COLS / 2, LINES / 2, COLS / 2);
    if (fourth == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(fourth, COLOR_PAIR(5));
    box(fourth, 0, 0);
    mvwaddstr(fourth, 1, 1, "This is a the fourth window");

    /* Setup Standard Screen */
    bkgd(COLOR_PAIR(1));
    addstr("This is the standard screen\n");
    addstr("Press Enter");

    /* Draw Standard Screen */
    refresh();
    getch();

    /* Draw Tiny Window */
    wrefresh(first);
    getch();
    wrefresh(second);
    getch();
    wrefresh(third);
    getch();
    wrefresh(fourth);
    getch();

    /* Draw Standard Screen */
    touchwin(stdscr);
    refresh();
    getch();

    endwin();
    return 0;
}
