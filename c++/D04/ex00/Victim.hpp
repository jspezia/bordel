/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 15:23:36 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/09 17:27:21 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_H
# define VICTIM_H

#include <iostream>

class Victim
{

public:

	Victim(std::string name);
	Victim(Victim const &src);
	~Victim();

	Victim		&operator=(Victim const &rhs);

	std::string		getName(void) const;
	void			getPolymorphed(void) const;

protected:

private:

	std::string		_name;

};

std::ostream		&operator<<(std::ostream &o, Victim const &i);

#endif /* !VICTIM_H */
