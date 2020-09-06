#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char word[7] = {0};
    // word[6] = '\0';

    srandom((unsigned)time(NULL));

    initscr();

    for (int x = 0; x < 200; x++)
    {
        for (int w = 0; w < 6; w++)
            word[w] = (random() % 26) + 'a';
        printw("%s\t", word);
    }
    addstr("\n Press Enter to dump the screen");
    refresh();
    getch();

    int r = scr_dump("dump.win");
    if (r == ERR)
    {
        addstr("Error writing window");
        refresh();
        getch();
        goto DONE;
    }

    addstr("File written; press Enter");
    refresh();
    getch();

DONE:
    endwin();
    return 0;
}
