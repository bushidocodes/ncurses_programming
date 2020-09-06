#include <ncurses.h>

int main()
{
    initscr();
    refresh();

    WINDOW *fred = newwin(0, 0, 0, 0);
    waddstr(fred, "This is Fred.\n");
    wrefresh(fred);
    getch();

    WINDOW *barney = dupwin(fred);
    waddstr(barney, "This is Barney\n");
    wrefresh(barney);
    getch();

    waddstr(fred, "Nice to see you!\n");
    wrefresh(fred);
    getch();

    waddstr(barney, "You too!\n");
    touchwin(barney);
    wrefresh(barney);
    getch();

    endwin();
    return 0;
}
