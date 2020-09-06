#include <ncurses.h>

int main()
{
    initscr();
    keypad(stdscr, true);
    noecho();

    int ch;
    do
    {
        switch (ch = getch())
        {
        case KEY_DOWN:
            addstr("Down\n");
            break;
        case KEY_UP:
            addstr("Up\n");
            break;
        case KEY_LEFT:
            addstr("Left\n");
            break;
        case KEY_RIGHT:
            addstr("Right\n");
            break;
        default:
            break;
        }
        refresh();
    } while (ch != '\n');

    endwin();
    return 0;
}
