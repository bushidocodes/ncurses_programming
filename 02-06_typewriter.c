#include <ncurses.h>

int main(){
	int ch;

	initscr();
	addstr("Type a few lines of text\n");
	addstr("Press ~ to quit\n");

	while ( (ch = getch()) != '~')
		;

	endwin();
	return 0;
}
