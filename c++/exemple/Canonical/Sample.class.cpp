/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 19:00:45 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/07 20:48:19 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) : _foo(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return;
}

Sample::Sample(int const n) : _foo(n)
{
	std::cout << "Parametric Constructor called" << std::endl;
	return;
}

Sample::Sample(Sample const & src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int		Sample::getFoo(void) const
{
	return (this->_foo);
}

Sample		&Sample::operator=(Sample const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_foo = rhs.getFoo();

	return (*this);
}

std::ostream		&operator<<(std::ostream &o, Sample const &i)
{
	o << "the vlue of _fo is : " << i.getFoo();

	return o;
}
