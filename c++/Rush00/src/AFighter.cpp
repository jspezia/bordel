#include <ncurses.h>
#include "AFighter.hpp"

AFighter::AFighter(void) {
}

AFighter::AFighter(std::string const &type, std::string const &weapon,
		int hp, int x, int y, int speed, std::string look)
	: MapObject(x, y, speed, look), _type(type), _weapon(weapon), _shield(hp), _maxShield(hp)
{
}

AFighter::AFighter(AFighter const &src) : MapObject(src)  {
	*this = src;
}

AFighter::~AFighter(void) {
}

std::string const & AFighter::getType() const {
	return this->_type;
}

std::string const & AFighter::getWeapon() const {
	return this->_weapon;
}

int AFighter::getShield() const {
	return this->_shield;
}

void	AFighter::setShield(int const nb)
{
	this->_shield = nb;
	return;
}

int AFighter::getMaxShield() const {
	return this->_maxShield;
}

AFighter & AFighter::operator=(AFighter const &rhs) {
	if (this != &rhs) {
		this->::MapObject::operator=(rhs);
		this->_type = rhs.getType();
		this->_weapon = rhs.getWeapon();
		this->_shield = rhs.getShield();
		this->_maxShield = rhs.getMaxShield();
	}
	return *this;
}

std::iostream & operator<<(std::iostream &o, AFighter const &i) {
	o << i << std::endl;
	return o;
}

