/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:57:42 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 19:55:51 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{

	public:
		ZombieHorde(int N);
		~ZombieHorde(void);
		void announce(void);

	private:
		int			_N;
		Zombie		*_horde;;


};

#endif /* !ZOMBIE_HORDE_HPP */
