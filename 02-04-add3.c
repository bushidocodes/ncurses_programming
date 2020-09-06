#include <ncurses.h>

int main(){
	char t1[] = "Shall I compare thee";
	char t2[] = " to a summer's day?";

	initscr();
	addstr(t1);
	addstr(t2);
	move(2,0);
	addstr("Though are more lovely...");
	refresh();
	getch();

	endwin();
	return 0;
}
