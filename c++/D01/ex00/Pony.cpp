/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:21:09 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 12:10:37 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, int height) : _name(name), _color(color), _height(height)
{
	std::cout << "Pony " << this->_name << " is born" << std::endl;
	return;
}

Pony::~Pony(void)
{
	std::cout << "Pony died" << std::endl;
	return;
}

void Pony::getName(void)
{
	std::cout << this->_name << std::endl;
}
