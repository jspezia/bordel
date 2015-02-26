/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:11:42 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/28 18:59:29 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct		s_pt
{
	double	x;
	double	y;
}					t_pt;


double		powerOfTen(int num)
{
	double	rst;
	int		i;

	rst = 1.0;
	i = 0;
	if(num >= 0)
	{
		while (i < num)
		{
			rst *= 10.0;
			i++;
		}
	}
	else
	{
		while (i < (0 - num))
		{
			rst *= 0.1;
			i++;
		}
	}
	return rst;
}


double		squareRoot(double a)
{
	double	z = a;
	double	rst = 0.0;
	int		max = 8;
	int		i;
	double	j = 1.0;

	for(i = max ; i > 0 ; i--)
	{
		if(z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
		{
			while( z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
			{
				j++;
				if(j >= 10) break;
			}
		j--;
		z -= (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i));
		rst += j * powerOfTen(i);
		j = 1.0;
		}
	}
	for(i = 0 ; i >= 0 - max ; i--)
	{
		if(z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
		{
			while( z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
			{
				j++;
			}
			j--;
			z -= (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i));
			rst += j * powerOfTen(i);
			j = 1.0;
		}
	}
	return rst;
}


double			module_i(double x, double y)
{
	double	ret;

	ret = x * x + (y * y) * -1;
	return (ret);
}

int			main()
{
	t_pt	pix;

	pix.x = 0;
	pix.y = 2;
	printf("%f \n", module_i(pix.x, pix.y));
	printf("%f \n", squareRoot(2.0));
	return (0);
}
