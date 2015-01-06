/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:47:59 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 17:29:47 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
	this->_type = "none";
	return;
}

ZombieEvent::~ZombieEvent(void)
{
	return;
}

void			ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
	return;
}

Zombie			*ZombieEvent::newZombie(std::string name)
{
	Zombie		*ZombieNew = new Zombie(name, this->_type);
	return (ZombieNew);
}

Zombie				*ZombieEvent::randomChump(void)
{
	int				r;
	std::string		name;
	Zombie			*randomZombie;

	std::srand(std::time(NULL));
	r = std::rand();
	if (r % 2 == 0)
		name = "toto";
	else
		name = "titi";
	randomZombie = this->newZombie(name);
	randomZombie->announce();
	return (randomZombie);
}
