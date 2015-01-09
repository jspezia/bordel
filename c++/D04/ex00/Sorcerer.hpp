/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 14:12:00 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/09 17:28:56 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_H
# define SORCERER_H

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer
{

public:

	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const &src);
	~Sorcerer();
	Sorcerer		&operator=(Sorcerer const &rhs);
	std::string		getName(void) const;
	std::string		getTitle(void) const;
	void			polymorph(Victim const &victim);
	void			polymorph(Peon const &peon);

private:

	std::string		_name;
	std::string		_title;

};

std::ostream		&operator<<(std::ostream &o, Sorcerer const &i);

#endif /* !SORCERER_H */
