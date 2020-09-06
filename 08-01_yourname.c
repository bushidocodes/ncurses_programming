#include <ncurses.h>
#include <string.h>

#define NAME_CAPACITY 32

int main()
{
    char name[NAME_CAPACITY];
    int ch;
    initscr();

    do
    {
        clear();
        addstr("Enter your name: ");
        getnstr(name, NAME_CAPACITY);
        if (strlen(name) == 0)
            continue;
        move(1, 0);
        printw("Your name is %s. ", name);
        printw("Is this correct? ");
        ch = getch();
    } while (ch != 'y');

    move(2, 0);
    printw("Pleased to meet you, %s.\n", name);
    getch();

    endwin();
    return 0;
}
