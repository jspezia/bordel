#include <ncurses.h>
#include <libft.h>
#include <unistd.h>

#define DELAY 50000

int			main(void)
{
	int		x_max;
	int		y_max;
	int		y;

	y = 0;
	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, y_max, x_max);
	while(y < y_max + 1)
	{
		clear();
		mvprintw(y, 0, "");
		refresh();
		usleep(DELAY);
		y++;
	}
	endwin();
	return (0);
}
