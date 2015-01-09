/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 15:23:45 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/09 16:25:17 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include <string>


Victim::Victim(std::string name) :
	_name(name)
{
	std::cout << "Some random victim called " << name
		<< " just popped !" << std::endl;
	return;
}


Victim::Victim(Victim const &src)
{
	*this = src;
}

Victim::~Victim(void)
{
	std::cout << "Victime " << this->_name
		<< " just died for no apparent reason !" << std::endl;
	return;
}

std::string		Victim::getName(void) const
{
	return this->_name;
}


Victim		&Victim::operator=(Victim const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Victim const &i)
{
	o << "I'm " << i.getName() << " and i like otters !" << std::endl;
	return o;
}

void	Victim::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a cute little sheep !"
		<< std::endl;
	return;
}
