#include "TodoModule.hpp"

#include "gkrellm.hpp"


TodoModule::TodoModule(int x, int y) :
	_x(x),
	_y(y)
{
	return ;
}

TodoModule::TodoModule(void)
{
	return ;
}

TodoModule::~TodoModule(void)
{
	return;
}

std::string			TodoModule::getInfo(void) const
{
	return (this->_info);
}

int					TodoModule::getX(void) const
{
	return (this->_x);
}

int					TodoModule::getY(void) const
{
	return (this->_y);
}

void				TodoModule::setInfo(std::string const info)
{
	this->_info = info;
}


TodoModule::TodoModule(TodoModule &src)
{
	*this = src;
	return ;
}

TodoModule				TodoModule::operator=(TodoModule &rhs)
{
	if (this != &rhs)
	{
		this->_info = rhs.getInfo();
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return (*this);
}


void				TodoModule::update(void)
{
	return ;
}

void				TodoModule::displayTerm(void)
{

	mvprintw(this->_x, this->_y, "//===============\\\\");
	mvprintw(this->_x + 1, this->_y, "||               ||");
	mvprintw(this->_x + 2, this->_y, "\\\\===============//");
	mvprintw(this->_x + 1, this->_y + 3, this->_info.c_str());
}
