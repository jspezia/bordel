/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 19:06:09 by jspezia           #+#    #+#             */
/*   Updated: 2015/04/09 20:08:38 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test.class.hpp"

int				main()
{
	test		instance1;
	test		instance3(instance1);

	std::cout << instance1 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance1;
	std::cout << instance3 << std::endl;

	return (0);
}
