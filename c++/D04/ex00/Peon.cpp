/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:52:54 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/09 17:21:24 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#include "Peon.hpp"
#include <iostream>
#include <string>


Peon::Peon(std::string name) :
	_name(name)
{
	std::cout << "Zog Zog";
	return;
}


Peon::Peon(Peon const &src)
{
	*this = src;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark...";
	return;
}

std::string		Peon::getName(void) const
{
	return this->_name;
}


Peon		&Peon::operator=(Peon const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Peon const &i)
{
	o << "I'm " << i.getName() << " and i like otters !";
	return o;
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a pink pony !";
	return;
}
