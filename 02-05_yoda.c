#include <ncurses.h>

int main(){
	int yoda = 874;
	int ss = 65;

	initscr();
	printw("Yoda is %d years one\n", yoda);
	printw("He has collected %d years of Social Security", yoda - ss);
	refresh();
	getch();

	endwin();
	return 0;
}
