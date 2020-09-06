#include <ncurses.h>

#define NAME_CAPACITY 32
#define PASSWORD_CAPACITY 32

int main()
{
    char name[NAME_CAPACITY];
    char password[PASSWORD_CAPACITY];

    initscr();

    addstr("Name: ");
    getnstr(name, NAME_CAPACITY - 1);

    noecho();
    addstr("Password: ");
    getnstr(password, PASSWORD_CAPACITY - 1);

    echo();
    printw("%s's password is '%s'\n", name, password);
    refresh();
    getch();

    endwin();
    return 0;
}
