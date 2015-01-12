#include "starwars.hpp"
#include "MapObject.hpp"
#include "Input.hpp"

MapObject::MapObject(void) {
}

MapObject::MapObject(int x, int y, int speed, std::string look) :
	_posX(x), _posY(y), _speed(speed), _look(look)
{
}

MapObject::MapObject(MapObject const &src) {
	*this = src;
}

MapObject::~MapObject(void) {

}

int MapObject::getPosX() const {
	return this->_posX;
}

int MapObject::getPosY() const {
	return this->_posY;
}

void	MapObject::setPosX(const int nb)
{
	this->_posX = nb;
}

void	MapObject::setPosY(const int nb)
{
	this->_posY = nb;
}



int MapObject::getSpeed() const {
	return this->_speed;
}

bool MapObject::moveY(int val, int width) {
	if (this->_posY + val < 0 || this->_posY + val > width) {
		return false;
	}
	this->_posY += val;
	return true;
}

bool MapObject::moveX(int val) {
	if (this->_posX + val <= CEILING || this->_posX + val >= FLOOR)
		return false;
	this->_posX += val;
	return true;
}

void MapObject::display() const {
	mvprintw(this->_posX, this->_posY, this->_look.c_str());
}

int MapObject::checkCollision(int x, int y) {
	return (this->_posX == x and std::abs(this->_posY - y) <= 4);
}

MapObject & MapObject::operator=(MapObject const &rhs) {
	if (this != &rhs) {
		this->_posX = rhs.getPosX();
		this->_posY = rhs.getPosY();
	}
	return *this;
}

std::ostream & operator<<(std::ostream &o, MapObject const &i) {
	o << i << std::endl;
	return o;
}

