#include <ncurses.h>

#define BUFFER_CAPACITY 80

int main()
{
    char buffer[BUFFER_CAPACITY + 1] = {0};

    initscr();

    addstr("Type. I'll wait...\n");
    refresh();
    napms(5000);

    addstr("Flushing buffer.\n");
    flushinp();
    addstr("Here is what you typed:\n");
    getnstr(buffer, BUFFER_CAPACITY);

    endwin();
    return 0;
}
