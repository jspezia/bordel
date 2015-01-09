/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 14:13:00 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/09 16:59:17 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

void	test(void)
{
	Sorcerer		sorcererA("nameA", "titleA");
	Victim			victimA("victim01");

	sorcererA.polymorph(victimA);
	return;
}

int		main()
{
	Sorcerer		sorcerer1("name00", "title00");
	Victim			victim1("victim01");
	Peon			peon1("peon01");

	victim1.getPolymorphed();
	test();
	std::cout << sorcerer1;
	std::cout << victim1;
	return (0);
}
