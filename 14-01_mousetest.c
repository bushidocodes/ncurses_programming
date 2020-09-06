#include <ncurses.h>

int main()
{
    initscr();

    if (!NCURSES_MOUSE_VERSION)
    {
        addstr("Mouse Functions Unavailable.\n");
        refresh();
        getch();
        goto done;
    }

    addstr("Mouse Functions Available.\n");
    mousemask(ALL_MOUSE_EVENTS, NULL);
    addstr("Mouse Active");
    refresh();
    getch();

done:
    endwin();
    return 0;
}
