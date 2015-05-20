#include <cstdlib>
#include "starwars.hpp"
#include "Map.hpp"
#include "TieFighter.hpp"

//extern std::ofstream g_ofs;
extern e_game g_status;

Map::Map(XWing *player, int up, int down, int width) :
	_look1(""),
	_look2(""),
	_look3(""),
	_up(up),
	_down(down),
	_width(width),
	_frame(0),
	_player(player)
{
	int			i;

	for (i = 0; i < 10; i++) {
		this->_collision[i][0] = 0;
		this->_collision[i][1] = -1;
	}
	this->_obstacles[10] = player;
	this->_collision[10][0] = 0;
	this->_collision[10][1] = -1;
	i = width / 3;
	while (i != 0)
	{
		this->_look1 += "__.";
		this->_look2 += "_._";
		this->_look3 += ".__";
		i--;
	}
	return;
}

Map::Map(Map const & src)
{
	*this = src;
	return;
}

Map::~Map(void)
{
	return;
}

Map			&Map::operator++(void)
{
	this->_frame = (this->_frame + 1) % 3;
	return *this;
}

Map			Map::operator++(int)
{
	Map		ret(*this);
	this->_frame = (this->_frame + 1) % 3;
	return (ret);
}

Map			&Map::operator=(Map const &rhs)
{
	if (this != &rhs)
	{
		this->_look1 = rhs.getLook1();
		this->_look2 = rhs.getLook2();
		this->_look3 = rhs.getLook3();
		this->_up = rhs.getUp();
		this->_down = rhs.getDown();
		this->_width = rhs.getWidth();
		this->_player = rhs.getPlayer();
	}
	return (*this);
}

int			Map::getUp(void) const
{
	return (this->_up);
}

int			Map::getDown(void) const
{
	return (this->_up);
}

int			Map::getFrame(void) const
{
	return (this->_width);
}

int			Map::getWidth(void) const
{
	return (this->_width);
}

std::string	Map::getLook1(void) const
{
	return (this->_look1);
}

std::string	Map::getLook2(void) const
{
	return (this->_look2);
}

std::string	Map::getLook3(void) const
{
	return (this->_look3);
}

void		Map::setFrame(int const nb)
{
	this->_frame = nb;
	return;
}

e_game		Map::getStatus(void) {
	return Map::_status;
}

void		Map::setStatus(e_game val) {
	Map::_status = val;
}

XWing 	*	Map::getPlayer(void) const {
	return this->_player;
}

void		Map::display(void)
{
	if (this->_frame == 0)
	{
		mvprintw(this->_up, 0, this->_look1.c_str());
		mvprintw(this->_down, 0, this->_look1.c_str());
	}
	if (this->_frame == 1)
	{
		mvprintw(this->_up, 0, this->_look2.c_str());
		mvprintw(this->_down, 0, this->_look2.c_str());
	}
	if (this->_frame == 2)
	{
		mvprintw(this->_up, 0, this->_look3.c_str());
		mvprintw(this->_down, 0, this->_look3.c_str());
	}
	for (int i = 0; i < 11; i++)
		if (this->_obstacles[i]) {
			int move = -(1 + this->_obstacles[i]->getSpeed());
			if (i < 10 && !(this->_obstacles[i]->moveY(move, this->_width))) {
				int diff = this->_down - this->_up - 1;
				int pos = rand() % diff + this->_up + 1;
				this->_obstacles[i]->setPosY(this->_width);
				this->_obstacles[i]->setPosX(pos);
				this->_collision[i][0] = pos;
				this->_collision[i][1] = this->_width;
			}
			else {
				if (i < 10)
					this->_collision[i][1] += move;
				for (int j = 0; j < 11; j++) {
					if (j != i) {
						int res = this->_obstacles[i]->checkCollision(this->_collision[j][0], this->_collision[j][1]);
						if (res == 2)
								g_status = DEATH;
						if (res && j < 10) {
							this->_obstacles[j]->setPosY(-2);
							this->_collision[j][1] = -2;
							return;
						}
					}
				}
				if (this->_obstacles[i])
					this->_obstacles[i]->display();
			}
		}
	return;
}

void	Map::addEnemy(void) {
	for(int i = 0; i < 10; i++)
		if (!this->_obstacles[i]) {
			int diff = this->_down - this->_up - 1;
			int pos = rand() % diff + this->_up + 1;
			this->_obstacles[i] = new TieFighter("Super Laser", 70, pos, this->_width, 2);
			this->_collision[i][0] = pos;
			this->_collision[i][1] = this->_width;
			std::ostringstream ss;
			ss << i;
			std::string str = "Enemy #" + ss.str() + " added to the map !";
//			mvprintw(43, 0, str.c_str());
			return;
		}
}

void	Map::updateXWingPos(XWing const &ref) {
			this->_collision[10][0] = ref.getPosX();
			this->_collision[10][1] = ref.getPosY();
}

e_game	Map::_status = PLAY;
