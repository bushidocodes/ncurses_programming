#include <ncurses.h>
#define FIRST_LEN 24
#define LAST_LEN 32

int main() {
	char first[FIRST_LEN] = {0};
	char last[LAST_LEN] = {0};

	initscr();
	addstr("What is your first name? >");
	refresh();
	getnstr(first, FIRST_LEN - 1);

	addstr("What is your last name? >");
	refresh();
	getnstr(last, LAST_LEN - 1);

	printw("Pleased to meet you, %s %s!", first, last);
	refresh();
	getch();

	endwin();
	return 0;
}
