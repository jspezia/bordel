#include <ncurses.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	initscr();
	noecho();
	curs_set(FALSE);
	sleep(1);
	endwin();
	return (0);
}
