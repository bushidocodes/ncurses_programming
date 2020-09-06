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

    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);

    while (true)
    {
        int ch = getch();
        if (ch == KEY_MOUSE)
        {
            MEVENT mort;
            getmouse(&mort);
            mvaddch(mort.y, mort.x, '*');
            refresh();
            continue;
        }
        if (ch == '\n')
            break;
    }

done:
    endwin();
    return 0;
}
