/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 20:22:10 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 20:30:59 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int					main()
{
	std::string		str;
	std::string		*ptr;
	std::string		&ref = str;

	str = "HI THIS IS BRAIN";
	ptr = &str;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return (0);
}
