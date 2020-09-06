#include <ncurses.h>

int main()
{
    char text1[] = "This is the first line\n";
    char text2[] = "Line two here";
    char text3[] = "The third line\n";
    char text4[] = "Fourth line here\n";
    char text5[] = "And the fifth line\n";

    initscr();

    addstr(text1);
    addstr(text3);
    addstr(text5);
    refresh();
    getch();

    move(1, 0);
    insstr(text2);
    refresh();
    getch();

    endwin();

    return 0;
}
