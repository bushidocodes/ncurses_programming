#include <ncurses.h>

int main()
{
    initscr();

    WINDOW *p = newpad(50, 100);
    if (p == NULL)
    {
        endwin();
        puts("Unable to create pad");
        return 1;
    }

    for (int i = 0; i < 500; i++)
    {
        wprintw(p, "%4d", i);
    }

    addstr("Press Enter to update");
    refresh();
    getch();

    prefresh(p, 0, 0, 5, 5, 16, 45);
    getch();

    endwin();
    return 0;
}
