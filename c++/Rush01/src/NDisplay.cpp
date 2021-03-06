#include "NDisplay.hpp"
#include <iostream>
#include <string>
#include <list>



NDisplay::NDisplay(std::string name) :
	_name(name),
	_N(0)
{
	return ;
}

NDisplay::NDisplay(void) :
	_name("System Monitor"),
	_N(0)
{
	return ;
}

NDisplay::~NDisplay(void)
{
	return;
}


std::string			NDisplay::getName(void) const
{
	return (this->_name);
}

NDisplay::NDisplay(NDisplay &src)
{
	*this = src;
	return ;
}



NDisplay				NDisplay::operator=(NDisplay &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return (*this);
}




void				NDisplay::addQuote(std::string const quotes)
{
	this->_quotes.push_back(quotes);
	this->_N += 1;
	return ;
}

void				NDisplay::removeQuote(std::string const quotes)
{
	std::list<std::string>::iterator	it;
	std::list<std::string>::iterator	del;

	for(it = this->_quotes.begin(); it != this->_quotes.end(); ++it)
	{
		if (*it == quotes)
		{
			del = it;
			this->_quotes.erase(del);
			this->_N -= 1;
		}
	}
	return ;
}

void				NDisplay::display(void)
{
	mvprintw(0, 20, this->_name.c_str());
	std::string			str;

	int		i = 2;
	std::list<std::string>::const_iterator	it;

	for(it = this->_quotes.begin(); it != this->_quotes.end(); ++it)
	{
		i++;
		mvprintw(i, 0, "||                    ||");
		mvprintw(i, 5, it->c_str());
	}
	mvprintw(2, 0, "//====================\\\\");
	mvprintw(6, 0, "\\\\====================//");

}
