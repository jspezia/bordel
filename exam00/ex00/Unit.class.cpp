
#include <iostream>
#include "Unit.class.hpp"


static int	INDEX = 0;

Unit::Unit(void) :
	_index(INDEX),
	_type("Unit"),
	_x(0), _y(0),
	_dam(0), _chp(0), _mhp(0)
{
	INDEX += 1;
	std::cout << "[CREATED] Unit #" << this->_index << ": Unit in "
		<< this->_x << "/" << this->_y << " with " << this->_chp
		<< "/" << this->_mhp << "HP damaging at " << this->_dam
		<< "." << std::endl;
	return;
}

Unit::Unit(std::string type, int x, int y, int dam, int chp, int mhp) :
	_index(INDEX),
	_type(type),
	_x(x), _y(y),
	_dam(dam),
	_chp(chp),
   	_mhp(mhp)
{
	INDEX += 1;
	std::cout << "[CREATED] Unit #" << this->_index << ": "
		<< this->_type << " in "
		<< this->_x << "/" << this->_y << " with " << this->_chp
		<< "/" << this->_mhp << "HP damaging at " << this->_dam
		<< "." << std::endl;
	return;
}


Unit::Unit(Unit const &src)
{
	*this = src;
	this->_index = INDEX;
	INDEX += 1;
	std::cout << "[CREATED] Unit #" << this->_index << ": "
		<< this->_type << " in "
		<< this->_x << "/" << this->_y << " with " << this->_chp
		<< "/" << this->_mhp << "HP damaging at " << this->_dam
		<< "." << std::endl;
}

Unit::~Unit(void)
{
	std::cout << "[DESTRUCTED] Unit #" << this->_index << ": "
		<< this->_type << " in "
		<< this->_x << "/" << this->_y << " with " << this->_chp
		<< "/" << this->_mhp << "HP damaging at " << this->_dam
		<< "." << std::endl;
	return;
}


Unit	&Unit::operator=(Unit const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		this->_x = rhs.getX();
		this->_y = rhs.getY();
		this->_dam = rhs.getDam();
		this->_chp = rhs.getCHP();
		this->_mhp = rhs.getMHP();
	}
	return (*this);
}

std::ostream		&operator<<(std::ostream &o, const Unit &i)
{
	o << "Unit #" << i.getIndex() << ": "
		<< i.getType() << " in "
		<< i.getX() << "/" << i.getY() << " with " << i.getCHP()
		<< "/" << i.getMHP() << "HP damaging at " << i.getDam()
		<< ".";
	return (o);
}

int			Unit::getIndex(void) const
{
	return (this->_index);
}

std::string	Unit::getType(void) const
{
	return (this->_type);
}

int			Unit::getX(void) const
{
	return (this->_x);
}

int			Unit::getY(void) const
{
	return (this->_y);
}

int			Unit::getDam(void) const
{
	return (this->_dam);
}

int			Unit::getCHP(void) const
{
	return (this->_chp);
}

int			Unit::getMHP(void) const
{
	return (this->_mhp);
}


void		Unit::die(void)
{
	this->_chp = 0;
	std::cout << "Unit #" << this->_index << " ("
		<< this->_type << ") died." << std::endl;
	return;
}

void		Unit::move(int x, int y)
{
	std::cout << "Unit #" << this->_index << " ("
		<< this->_type << ") is moving from "
		<< this->_x << "/" << this->_y << " to "
		<< x << "/" << y
		<<"." << std::endl;
	this->_x = x;
	this->_y = y;
	return;
}

void		Unit::attack(Unit &target) const
{
	if (this->_chp == 0)
		return;
	std::cout << "Unit #" << this->_index
		<< " (" << this->_type << ") damaged unit #"
		<< target.getIndex() << " ("
		<< target.getType() << ")."
		<< std::endl;
	target -= this->_dam;
	return;
}

void		Unit::setCHP(int i)
{
	if (i > this->_mhp)
		this->_chp = this->_mhp;
	else if (i <= 0)
	{
		this->_chp = 0;
		this->die();
	}
	else
		this->_chp = i;
	return;
}

void		operator+=(Unit &o, int i)
{
	int		a;
	a = o.getCHP();
	o.setCHP(a + i);
	return;
}

void		operator-=(Unit &o, int i)
{
	int		a;
	a = o.getCHP();
	o.setCHP(a - i);
	return;
}
