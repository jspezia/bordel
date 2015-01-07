/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 19:00:45 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/07 19:05:49 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Desstructor called" << std::endl;
	return;
}

void	Sample::bar(char const c) const
{
	std::cout << "Member fonction bar called with char overload : " << c << std::endl;
	return;
}

void	Sample::bar(int const n) const
{
	std::cout << "Member fonction bar called with int overload : " << n << std::endl;
	return;
}

void	Sample::bar(float const z) const
{
	std::cout << "Member fonction bar called with float overload : " << z << std::endl;
	return;
}

void	Sample::bar(Sample const & i) const
{
	std::cout << "Member fonction bar called with Sample.class overload." << std::endl;
	return;
}
