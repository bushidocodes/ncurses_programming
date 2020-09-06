#include <ncurses.h>

int main()
{
    initscr();

    addstr("Type a key: ");
    refresh();

    int key1 = getch();
    // clear();

    move(1, 0);
    addstr("Type the same key: ");
    noecho();
    int key2 = getch();
    move(2, 0);
    if (key1 == key2)
    {
        addstr("The keys match!");
    }
    else
    {
        addstr("The keys don't match!");
    }

    getch();
    refresh();

    endwin();
    return 0;
}
