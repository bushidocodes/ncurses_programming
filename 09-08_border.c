#include <errno.h>
#include <ncurses.h>
#include <string.h>

int main()
{
    initscr();
    border(0, 0, 0, 0, 0, 0, 0, 0);
    move(1, 1);

    addstr("Now that's a swell border!");
    refresh();
    getch();

    endwin();
    return 0;
}
