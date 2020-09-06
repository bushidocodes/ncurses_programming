#include <ncurses.h>

int main()
{
    initscr();
    start_color();

    touchwin(stdscr);
    refresh();

    init_pair(1, COLOR_WHITE, COLOR_GREEN);

    WINDOW *alpha = newwin(7, 20, 3, 10);
    if (!alpha)
    {
        endwin();
        puts("Unable to create windows");
        return 1;
    }

    wbkgd(alpha, COLOR_PAIR(1));
    mvwaddstr(alpha, 1, 2, "Window Alpha");
    wrefresh(alpha);
    getch();

    mvwin(alpha, 10, 43);
    touchwin(stdscr);
    refresh();
    mvwaddstr(alpha, 2, 2, "Moved!");
    wrefresh(alpha);
    getch();

    endwin();
    return 0;
}
