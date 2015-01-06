/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:24:35 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 15:47:24 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {

	public:
		Zombie(std::string name, std::string type);
		~Zombie(void);
		void announce(void);

	private:
		std::string	const	_name;
		std::string	const	_type;

};

#endif /* !ZOMBIE_HPP */
