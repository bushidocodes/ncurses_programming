#include <ncurses.h>

#define NAME_CAPACITY 32

int main()
{
    int value = 0;

    initscr();

    addstr("Press any key to begin:\n");
    refresh();
    getch();

    /* Set screen to non-blocking mode */
    nodelay(stdscr, true);

    addstr("Press any key to start the loop!\n");

    while (getch() == ERR)
    {
        printw("%d\r", value++);
        refresh();
    }

    endwin();
    return 0;
}
