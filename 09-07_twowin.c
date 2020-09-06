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
    WINDOW *first = newwin(LINES, COLS / 2, 0, 0);
    if (first == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(first, COLOR_PAIR(2));
    waddstr(first, "This is a the first window\n");

    /* Setup Second */
    WINDOW *second = newwin(LINES, COLS / 2, 0, COLS / 2);
    if (second == NULL)
    {
        endwin();
        puts("Unable to create window");
        return 1;
    }
    wbkgd(second, COLOR_PAIR(3));
    waddstr(second, "This is a the second window\n");

    /* Setup Standard Screen */
    bkgd(COLOR_PAIR(1));

    /* Draw Standard Screen */
    refresh();
    getch();

    /* Draw Tiny Window */
    wrefresh(first);
    getch();
    wrefresh(second);
    getch();

    delwin(first);
    waddstr(second, "First window deleted");
    touchwin(stdscr);
    refresh();
    touchwin(second);
    wrefresh(second);
    getch();

    /* Draw Standard Screen */
    touchwin(stdscr);
    refresh();
    getch();

    endwin();
    return 0;
}
