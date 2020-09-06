#include <ncurses.h>
#include <string.h>

int main()
{
    initscr();
    char *original = "silly";
    char *replace = "fat";

    printw("Where did that %s cat go?", original);
    refresh();
    getch();

    for (int i = 0; i < strlen(original); i++)
    {
        move(0, 15);
        delch();
        refresh();
        napms(250);
    }

    for (int i = 0; i < strlen(replace); i++)
    {
        move(0, 15 + i);
        insch(replace[i]);
        refresh();
        napms(250);
    }

    getch();
    endwin();
    return 0;
}
