/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:57:36 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 19:55:48 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _N(N)
{
	this->_horde = new Zombie[N];
	return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->_horde;
	return;
}

void		ZombieHorde::announce(void)
{
	int		i;

	i = -1;
	while(++i != this->_N)
		this->_horde[i].announce();
	return;
}
