#include "XWing.hpp"
#include "starwars.hpp"
#include "Input.hpp"

//extern std::ofstream g_ofs;
e_game extern g_status;

XWing::XWing() {
}

XWing::XWing(std::string const &weapon,
		int hp, int x, int y, int speed)
	: AFighter("X-Wing", weapon, hp, x, y, speed, "}>")
{
	for (int i = 0; i < 5; i++)
		_projectile[i] = new Projectile(x, y, 20, "-", false);
}

XWing::XWing(XWing const &src) : AFighter(src) {
	*this = src;
}

XWing::~XWing(void) {
}

void XWing::shoot(Input &inst)
{
	if (inst.getKey() == "Space")
	{
		for(int i = 0; i < 5; i++) {
			if (this->_projectile[i]->getRight() == false)
			{
				this->_projectile[i]->setPosY(this->_posY);
				this->_projectile[i]->setPosX(this->_posX);
				this->_projectile[i]->setRight(true);
				return;
			}
		}
	}
}



XWing & XWing::operator=(XWing const &rhs) {
	if (this != &rhs)
	{
		this->AFighter::operator=(rhs);
	}
	return *this;
}

std::ostream & operator<<(std::ostream &o, XWing const &i) {
	o << i << std::endl;
	return o;
}

bool			XWing::move(Input &inst)
{
	if (inst.getKey() == "Up")
		this->_posX -= 1;
	if (inst.getKey() == "Down")
		this->_posX += 1;
	if (inst.getKey() == "Left")
	{
		if (this->_posY == 0)
			return true;
		this->_posY -= 1;
	}
	if (inst.getKey() == "Right")
	{
		if (this->_posY == inst.getMaxY() - 1)
			return true;
		this->_posY += 1;
	}
	this->shoot(inst);
	for(int i = 0; i < 5; i++) {
		if (this->_projectile[i]->getRight() == true)
		{
			attron(COLOR_PAIR(2));
			this->_projectile[i]->display();
			attron(COLOR_PAIR(1));
			if (this->_projectile[i]->moveY(10, inst.getMaxY()) == false)
				this->_projectile[i]->setRight(false);
		}
	}
	if (this->_posX == CEILING || this->_posX == FLOOR)
		return false;
	return true;
}

int 		XWing::checkCollision(int x, int y) {
	if (this->MapObject::checkCollision(x, y)) {
		g_status = DEATH;
		return 2;
	}
	for (int i = 0; i < 5; i++) {
		if (this->_projectile[i]->getPosX() == x
				&&	std::abs(this->_projectile[i]->getPosY() - y) <= 5) {
			this->_projectile[i]->setRight(false);
			return 1;
		}
	}
	return 0;
}

void		XWing::displayInfo()
{
	attron(COLOR_PAIR(3));
	if (this->_shield == 5)
		mvprintw(4, 15, "REMAINING SHIELDS [=====]");
	if (this->_shield == 4)
		mvprintw(4, 15, "REMAINING SHIELDS [==== ]");
	if (this->_shield == 3)
		mvprintw(4, 15, "REMAINING SHIELDS [===  ]");
	if (this->_shield == 2)
		mvprintw(4, 15, "REMAINING SHIELDS [==   ]");
	if (this->_shield == 1)
		mvprintw(4, 15, "REMAINING SHIELDS [=    ]");
	if (this->_shield == 0)
		mvprintw(4, 15, "REMAINING SHIELDS [     ]");
	attron(COLOR_PAIR(1));
	mvprintw(4, 42, ",  WEAPON : ");
	mvprintw(4, 55, this->_weapon.c_str());
}
