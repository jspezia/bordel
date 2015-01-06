/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:06:16 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 20:18:27 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

void			todo(void)
{
	ZombieHorde		wave1(6);

	wave1.announce();
	return;
}

int					main()
{
	std::srand(std::time(NULL));

	ZombieHorde		*horde = new ZombieHorde(4);

	todo();
	horde->announce();
	delete horde;
	return (0);
}
