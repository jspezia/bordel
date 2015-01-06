/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:24:35 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 20:01:33 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{

	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);

	private:
		std::string		_name;
		std::string		_type;

};

#endif /* !ZOMBIE_HPP */
