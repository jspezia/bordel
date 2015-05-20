#include "starwars.hpp"
#include "Input.hpp"
#include "Deathstar.hpp"
#include "Input.hpp"
#include <unistd.h>


Deathstar::Deathstar(int maxX) :
	_maxX(maxX),
	_hp(999)
{
	return;
}

Deathstar::Deathstar(void)
{
	return;
}

Deathstar::~Deathstar(void)
{
	return;
}

Deathstar	&Deathstar::operator=(Deathstar const &rhs)
{
	if (this != &rhs)
	{
		this->_maxX = rhs.getMaxX();
		this->_hp = rhs.getHp();
	}
	return (*this);
}

std::ostream		&operator<<(std::ostream &o, Deathstar const &i)
{
	o << i << std::endl;
	return (o);
}

int			Deathstar::getHp(void) const
{
	return (this->_hp);
}

int			Deathstar::getMaxX(void) const
{
	return (this->_maxX);
}

void			Deathstar::emergence(int i)
{
	int		xmax;
	int		x;

	xmax = this->_maxX - (30 + i);

	x = 10;
	mvprintw(x++, xmax, "             ______");
	mvprintw(x++, xmax, "        ,-~\"        \"~-.");
	mvprintw(x++, xmax, "     ,^ ____      \\     ^.");
	mvprintw(x++, xmax, "    / .^    ^.       |    \\");
	mvprintw(x++, xmax, "   Y  l  o   !   |       \\ Y");
	mvprintw(x++, xmax, "  l_  `.____.'      |    _,[");
	mvprintw(x++, xmax, "  |^~\"-----------------\"\"~ ^|");
	mvprintw(x++, xmax, "   Y  l  o   !   |       \\ Y");
	mvprintw(x++, xmax, "    \\     \\      |        /");
	mvprintw(x++, xmax, "      ^.       |   /  ..^");
	mvprintw(x++, xmax, "         \"-.._____.,-\"");
	return;
}


