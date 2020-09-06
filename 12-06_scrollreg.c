#include <ncurses.h>

int main()
{
    char text[] = "Scroll me! ";

    initscr();

    bkgd('.');
    scrollok(stdscr, true);
    setscrreg(3, LINES - 3);

    for (int i = 0; i < 600; i++)
    {
        addstr(text);
        napms(25);
        refresh();
    }
    getch();

    endwin();
    return 0;
}
