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

    addstr("New pad created");
    refresh();
    getch();

    endwin();
    return 0;
}
