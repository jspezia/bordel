/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:23:56 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 12:10:35 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

void			ponyOnTheHeap(void)
{
	Pony		bob = Pony("bob", "white", 321);

	bob.getName();
}

void			ponyOnTheStack(void)
{
	Pony		*tony = new Pony("tony", "black", 123);

	tony->getName();
	delete tony;
}

int			main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}
