/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:18:38 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/29 11:36:46 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_env		*init_env(void)
{
	t_env	*e;

	if (!(e = malloc(sizeof(t_env))))
		exit(-1);
	if (!(e->mlx = mlx_init()))
		exit(-1);
	if (!(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "Fractal")))
		exit(-1);
	if (!(e->c = malloc(sizeof(t_pt))))
		exit(-1);
	e->c->x = 0.0;
	e->c->y = 0.0;
	e->origin->x = 0.0;
	e->origin->y = 0.0;
	e->zoom = 1;
	return (e);
}

int			loop_hook(t_env *e)
{
	criss_cross(e, &fractal_julia);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}

int			main()
{
	t_env		*e;

	e = init_env();
	e->img = create_new_image(e, W_WIDTH, W_HEIGHT);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, &key_release, e);
	mlx_loop_hook(e->mlx, &loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
