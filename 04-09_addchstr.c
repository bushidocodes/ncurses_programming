#include <ncurses.h>

int main(){
	chtype string[] = {
		'H' | A_BOLD,
		'e',
		'l',
		'l' | A_REVERSE,
		'o',
		'!' | A_UNDERLINE,
		'\0'
	};

	initscr();

	addchstr(string);
	refresh();
	getch();

	endwin();
	return 0;
}
