/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t02.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 10:25:03 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 10:39:08 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void		byPtr(std::string *str)
{
	*str += " and ponies";
}

void		byConstPtr(std::string const * str)
{
	std::cout << *str << std::endl;
}

void		byRef(std::string &str)
{
	str += " and ponies";
}

void		byConstRef(std::string const &str)
{
	std::cout << str << std::endl;
}

int			main()
{
	std::string		str = "i like butterflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";

	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return (0);
}
