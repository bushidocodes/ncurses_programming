#include <ncurses.h>

int main()
{
    initscr();
    refresh();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    WINDOW *red = newwin(10, 24, 5, 10);
    WINDOW *blue = newwin(10, 20, 5, 40);
    if (!red || !blue)
    {
        endwin();
        puts("Unable to create windows");
        return 1;
    }

    wbkgd(red, COLOR_PAIR(1));
    wbkgd(blue, COLOR_PAIR(2));

    for (int i = 0; i < 34; i++)
    {
        waddstr(red, "red    ");
        waddstr(blue, "   blue");
    }

    wrefresh(red);
    wrefresh(blue);
    getch();

    copywin(red, blue, 0, 0, 1, 4, 5, 10, false);
    wrefresh(blue);
    getch();

    endwin();
    return 0;
}
