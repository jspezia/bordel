#include <ncurses.h>
#include "TieFighter.hpp"
#include "Input.hpp"

TieFighter::TieFighter() {

}

TieFighter::TieFighter(std::string const &weapon,
		int hp, int x, int y, int speed)
	: AFighter("TieFighter", weapon, hp, x, y, speed, "]o[")
{
}

TieFighter::TieFighter(TieFighter const &src) : AFighter(src) {
	*this = src;
}

TieFighter::~TieFighter() {

}

void TieFighter::shoot(Input &i) {
	std::cout << i.getMaxY() << std::endl;
	std::cout << this->_type << " fires with " << this->_weapon << std::endl;
}

int 	TieFighter::checkCollision(int x, int y) {
	return this->MapObject::checkCollision(x, y);
}

TieFighter & TieFighter::operator=(TieFighter const &rhs) {
	if (this != &rhs) {
		this->AFighter::operator=(rhs);
	}
	return *this;
}

std::ostream & operator<<(std::ostream &o, TieFighter const &i) {
	o << i << std::endl;
	return o;
}

