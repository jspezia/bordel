/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 14:12:44 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/09 17:28:40 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include <string>


Sorcerer::Sorcerer(std::string name, std::string title) :
	_name(name), _title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
	return;
}


Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title
		<< " is dead. Consequences will nerver be the same !" << std::endl;
	return;
}

std::string		Sorcerer::getName(void) const
{
	return this->_name;
}

std::string		Sorcerer::getTitle(void) const
{
	return this->_title;
}



Sorcerer		&Sorcerer::operator=(Sorcerer const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_title = rhs.getTitle();
	}
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Sorcerer const &i)
{
	o << "I am " << i.getName() << ", " << i.getTitle()
		<< ", and I like ponies !" << std::endl;
	return o;
}

void			Sorcerer::polymorph(Victim const &victime)
{
	victime.getPolymorphed();
	return;
}


void			Sorcerer::polymorph(Peon const &peon)
{
	peon.getPolymorphed();
	return;
}
