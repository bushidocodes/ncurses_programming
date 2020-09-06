#include <ncurses.h>

int main()
{
    initscr();

    curs_set(0);
    addstr("  <- The cursor has been turned off");
    move(0, 0);
    refresh();
    getch();

    curs_set(1);
    addstr("  <- The cursor has been turned on");
    move(0, 0);
    refresh();
    getch();

    curs_set(2);
    addstr("  <- The cursor has been turned very on");
    move(0, 0);
    refresh();
    getch();

    endwin();
    return 0;
}
