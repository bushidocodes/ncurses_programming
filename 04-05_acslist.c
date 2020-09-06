#include <ncurses.h>

int main(){
	initscr();

	for (int i = 0; i < 127; i++){
		printw("\t%2X:", i);
		addch(A_ALTCHARSET | i);
		addch('\n');
	}

	refresh();
	getch();
	endwin();
	return 0;
}
