/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t00.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 10:55:51 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 11:02:06 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int			main()
{
	std::ifstream		ifs("numbers");
	unsigned int		dst;
	unsigned int		dst2;

	ifs >> dst >> dst2;
	std:: cout << dst << " " << dst2 << std::endl;
	ifs.close();


	std::ofstream		ofs("test.out");

	ofs << "Hello" << std::endl;
	ofs.close();
}
