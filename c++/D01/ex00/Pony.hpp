/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:04:32 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 12:10:40 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <string>

class Pony {

	public:

		Pony(std::string name, std::string color, int height);
		~Pony(void);
		void getName(void);

	private:
		std::string		_name;
		std::string		_color;
		int				_height;

};

#endif /* !PONY_HPP */
