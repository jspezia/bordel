/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:48:12 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 16:08:05 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

#include <string>
#include "Zombie.hpp"

class ZombieEvent {

	public:
		ZombieEvent(void);
		~ZombieEvent(void);
		void		setZombieType(std::string type);
		Zombie		*newZombie(std::string name);
		Zombie		*randomChump(void);

	private:
		std::string		_type;

};

#endif /* !ZOMBIE_EVENT_HPP */
