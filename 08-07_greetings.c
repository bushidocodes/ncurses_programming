#include <ncurses.h>

#define FIRST_CAPACITY 32
#define LAST_CAPACITY 32

int main()
{
    char first[FIRST_CAPACITY];
    char last[LAST_CAPACITY];

    initscr();

    addstr("First name: ");
    getnstr(first, FIRST_CAPACITY - 1);

    addstr("Last name: ");
    getnstr(last, LAST_CAPACITY - 1);

    printw("Pleased to meet you, %s %s\n", first, last);
    refresh();
    getch();

    endwin();
    return 0;
}
