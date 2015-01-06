/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:25:42 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 20:13:47 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	if (std::rand() % 2 == 0)
		this->_name = "Marco";
	else
		this->_name = "Polo";
	this->_type = "zombie";
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie <" << this->_name << "> died." << std::endl;
	return;
}

void		Zombie::announce(void)
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiinnnsss" << std::endl;
}
