#include "UsernameModule.hpp"

#include "gkrellm.hpp"


UsernameModule::UsernameModule(int x, int y) :
	_x(x),
	_y(y)
{
	return ;
}

UsernameModule::UsernameModule(void)
{
	return ;
}

UsernameModule::~UsernameModule(void)
{
	return;
}

std::string			UsernameModule::getInfo(void) const
{
	return (this->_info);
}

int					UsernameModule::getX(void) const
{
	return (this->_x);
}

int					UsernameModule::getY(void) const
{
	return (this->_y);
}

void				UsernameModule::setInfo(std::string const info)
{
	this->_info = info;
}


UsernameModule::UsernameModule(UsernameModule &src)
{
	*this = src;
	return ;
}

UsernameModule				UsernameModule::operator=(UsernameModule &rhs)
{
	if (this != &rhs)
	{
		this->_info = rhs.getInfo();
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return (*this);
}


void				UsernameModule::update(void)
{
	return ;
}

void				UsernameModule::displayTerm(void)
{
	mvprintw(this->_x, this->_y, this->_info.c_str());
}
