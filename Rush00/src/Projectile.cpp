#include "starwars.hpp"
#include "Projectile.hpp"
#include "MapObject.hpp"

Projectile::Projectile(void)
{
	return;
}

Projectile::Projectile(int x, int y, int speed, std::string look, bool right)
	: MapObject(x, y, speed, look),
	_right(right), _dmg(1)
{
	std::string intro = "Missile fire !";
	mvprintw(42, 0, intro.c_str());
}

Projectile::Projectile(Projectile const &src) : MapObject(src)
{
	std::string intro = "Missile fire !";
	mvprintw(42, 0, intro.c_str());
}


Projectile::~Projectile(void)
{
	return;
}

Projectile		&Projectile::operator=(Projectile const &rhs)
{
	if (this != &rhs)
	{
		this->::MapObject::operator=(rhs);
		this->_dmg = 1;
		this->_right = rhs.getRight();
	}
	return *this;
}

int			Projectile::getDmg(void) const
{
	return (this->_dmg);
}

bool		Projectile::getRight(void) const
{
	return (this->_right);
}

void		Projectile::setRight(bool const right)
{
	this->_right = right;
}
