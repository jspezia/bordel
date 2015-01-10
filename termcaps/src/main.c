#include <ncurses.h>
#include <libft.h>
#include <unistd.h>

#define DELAY 50000

void		ft_route(int x_max, int y)
{
	int		x;

	x = 0;
	while(x < x_max)
	{
		mvprintw(y, x, "_");
		x += 1;
	}
}

void		ft_dechet(int y, int x, int x_max)
{
	int		b1;
	int		b2;

	b1 = x_max / 2;
	b2 = b1;
		if (x <= b1)
			b1 = x - 1;
		if (x <= b2 + 5)
			b2 = x - 6;
		mvprintw(y - 1, b1, "oO");
		mvprintw(y, b2, "ooOOOo");
}

void		ft_bulldozer(int x, int y, int x_max)
{
	mvprintw(y - 1, x + 1, "/__i_[TT]_");
	mvprintw(y, x, "/\"(_)oooo(_)");
	ft_dechet(y, x, x_max);
}

void		ft_arbre(int x, int y)
{
	mvprintw(y, x, "||");
}

int			main(void)
{
	int		x_max;
	int		y_max;
	int		y;
	int		x;

	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, y_max, x_max);
	y = (2 * y_max) / 3;
	x = x_max - 15;
	while(x > -1)
	{
		clear();
		ft_route(x_max, y);
//		ft_arbre(x_max, y);
		ft_bulldozer(x, y, x_max);
		refresh();
		usleep(DELAY);
		x--;
	}
	endwin();
	return (0);
}
