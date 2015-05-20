#include "Boss.hpp"
#include "starwars.hpp"
#include <ctime>
#include <unistd.h>

Boss::Boss(void) : _str("toto")
{
	mvprintw(20, 20, "sdfhgnhdfhdhjdg");
	mvprintw(19, 19, "sdfhgnhdfhdhjdg");
	mvprintw(18, 18, "sdfhgnhdfhdhjdg");
	sleep(10);
	return;
}

Boss::Boss(Boss const &src)
{
	*this = src;
}

Boss::~Boss(void)
{
	return;
}



Boss		&Boss::operator=(Boss const &rhs)
{
	if (this != &rhs)
	{
		this->_str = rhs.getStr();
	}
	return *this;
}


std::string		Boss::getStr(void) const
{
	return (this->_str);
}

/*
void			Boss::show(Input &inst)
{
	int		i = 0;
	int		ymax;

	ymax = inst.getMaxY();
	while (i != 20)
	{
		mvprintw(15, ymax - i, "             ______");
		mvprintw(15, ymax - i, "        ,-~"        "~-.");
		mvprintw(15, ymax - i, "     ,^ ____      \\     ^.");
		mvprintw(15, ymax - i, "    / .^    ^.       |    \\");
		mvprintw(15, ymax - i, "   Y  l  o   !   |       \\ Y");
		mvprintw(15, ymax - i, "  l_  `.____.'      |    _,[");
		mvprintw(15, ymax - i, "  |^~\"-----------------\"\"~ ^|");
		mvprintw(15, ymax - i, "   Y  l  o   !   |       \\ Y");
		mvprintw(15, ymax - i, "    \\     \\      |        /");
		mvprintw(15, ymax - i, "      ^.       |   /  ..^");
		mvprintw(15, ymax - i, "         \"-.._____.,-\"");
		i++;
		usleep(500000);
	}
	return;
}
*/

