#include <ncurses.h>

int main()
{
    initscr();
    refresh();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    WINDOW *red = newwin(10, 20, 2, 22);
    WINDOW *blue = newwin(10, 20, 5, 32);
    if (!red || !blue)
    {
        endwin();
        puts("Unable to create windows");
        return 1;
    }

    wbkgd(red, COLOR_PAIR(1));
    wbkgd(blue, COLOR_PAIR(2));

    for (int i = 0; i < 30; i++)
    {
        waddstr(red, "o e l y ");
        waddstr(blue, " r a   v");
    }

    wrefresh(red);
    wrefresh(blue);
    getch();

    overlay(red, blue);
    wrefresh(blue);
    getch();

    endwin();
    return 0;
}
