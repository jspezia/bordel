#include "TimeModule.hpp"

#include "gkrellm.hpp"


TimeModule::TimeModule(int x, int y) :
	_x(x),
	_y(y)
{
	return ;
}

TimeModule::TimeModule(void)
{
	return ;
}

TimeModule::~TimeModule(void)
{
	return;
}

std::string			TimeModule::getInfo(void) const
{
	return (this->_info);
}

int					TimeModule::getX(void) const
{
	return (this->_x);
}

int					TimeModule::getY(void) const
{
	return (this->_y);
}

TimeModule::TimeModule(TimeModule &src)
{
	*this = src;
	return ;
}

TimeModule				TimeModule::operator=(TimeModule &rhs)
{
	if (this != &rhs)
	{
		this->_info = rhs.getInfo();
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return (*this);
}


void				TimeModule::update(void)
{
	time_t temps;
	struct tm date;

	time(&temps);
	date=*localtime(&temps);
	this->_info = asctime(&date);

	return ;
}

void				TimeModule::displayTerm(void)
{
	mvprintw(0, 20, "System Monitor");
	mvprintw(this->_x, this->_y, "//==========================\\\\");
	mvprintw(this->_x + 1, this->_y, "||                          ||");
	mvprintw(this->_x + 1, this->_y + 3, this->_info.c_str());
	mvprintw(this->_x + 1, this->_y + 28, "||");
	mvprintw(this->_x + 2, this->_y, "\\\\==========================//");
}
