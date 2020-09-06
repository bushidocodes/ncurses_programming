#include <ncurses.h>

int main()
{
    WINDOW *grandpa, *father, *son;
    int g1, gc;

    initscr();
    refresh();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_RED, COLOR_YELLOW);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);

    grandpa = newwin(LINES - 4, COLS - 10, 2, 5);
    getmaxyx(grandpa, g1, gc);
    father = derwin(grandpa, g1 / 2, gc, g1 / 2, 0);
    son = derwin(father, g1 / 2, 10, 0, (gc - 4) / 2);

    wbkgd(grandpa, COLOR_PAIR(1));
    waddstr(grandpa, "I am grandpa\n");
    wbkgd(father, COLOR_PAIR(2));
    waddstr(father, "I am father\n");
    wclrtobot(father);
    wbkgd(son, COLOR_PAIR(3));
    waddstr(son, "I am son\n");
    wrefresh(grandpa);
    getch();

    endwin();
    return 0;
}
