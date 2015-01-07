/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 19:06:09 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/07 19:18:01 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.class.hpp"

int				main()
{
	Sample		test;
	char		c;
	int			n;
	float		z;
	Sample		cpy;

	c = 'c';
	n = 12;
	z = 1.23;
	test.bar(c);
	test.bar(n);
	test.bar(z);
	test.bar(cpy);
	return (0);
}
