#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    initscr();

    addstr("Press Enter to restore the screen");
    refresh();
    getch();

    int r = scr_restore("dump.win");
    if (r == ERR)
    {
        addstr("Error reading window file");
        refresh();
        getch();
        goto DONE;
    }

    refresh();
    getch();

DONE:
    endwin();
    return 0;
}
