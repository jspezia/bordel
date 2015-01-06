/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:06:16 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 17:48:29 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void				whatever(void)
{
	Zombie			zombie1("toto", "boulanger");
	std::cout << "Un zombie apparait sur le toit" << std::endl;
	zombie1.announce();
	std::cout << "puis saute..." << std::endl;
}

int					main()
{
	ZombieEvent		event;
	Zombie			*zombie2;
	Zombie			*zombie3;
	Zombie			*zombie4;

	std::cout << "John se balade dans la ville quand soudain:" << std::endl;
	whatever();
	std::cout << "3 zombies apparaissent :" << std::endl;
	std::cout << "roger:" << std::endl;
	zombie2 = event.newZombie("roger");
	zombie2->announce();
	std::cout << "un electricien" << std::endl;
	event.setZombieType("electricien");
	zombie3 = event.newZombie("luc");
	zombie3->announce();
	std::cout << "et ...?" << std::endl;
	zombie4 = event.randomChump();
	std::cout << "john tue les 3 zombies" << std::endl;
	delete zombie2;
	delete zombie3;
	delete zombie4;
	return (0);
}
