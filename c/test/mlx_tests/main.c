/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:22:33 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/29 20:41:10 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/Xutil.h>
// #include <sys/ipc.h>
// #include <sys/shm.h>
// #include <X11/extensions/XShm.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx_tests.h"
#include "libft.h"

static int		pointer_motion_hook(int x, int y, void *param)
{
	t_env	*e;

	e = (t_env *)param;
	printf("Mouse at %d, %d\n", x, y);
}

static int		loop_hook(t_env *e)
{
	// clear_img(e->img);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

static int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

static int		key_hook(int keycode, void *param)
{
	t_env	*e;

	e = (t_env *)param;
	printf("Key (released) code: [%d]\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

static int		mouse_hook(int button, int x, int y, void *param)
{
	t_env	*e;

	e = (t_env *)param;
	// mlx_string_put(e->mlx, e->win, 10, 10, 0xAAAAAA, "hello");
	printf("Mouse code: [%d]\n", button);
	return (0);
}

t_img			*create_new_image(t_env *e, int width, int height)
{
	t_img	*new_img;

	if (!(new_img = malloc(sizeof(t_img))))
	{
		perror("[MLX]: New image alloc failed.");
		exit(-1);
	}
	new_img->e = e;
	if ((new_img->id = mlx_new_image(e->mlx, width, height)) == NULL)
	{
		perror("[MLX]: New image creation failed.");
		exit(-1);
	}
	new_img->width = width;
	new_img->height = height;
	new_img->addr = mlx_get_data_addr(new_img->id, &new_img->bpp,
										&new_img->lsize, &new_img->endian);
	e->img = new_img->id;
	return (new_img);
}

static int		set_env(t_env *env)
{
	if ((env->mlx = mlx_init()) == NULL)
	{
		perror("[MLX]: Connexion to server X failed.");
		exit(-1);
	}
	if (!(env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "-- TITLE --")))
	{
		perror("[MLX]: New window creation failed.");
		exit(-1);
	}
	return (EXIT_SUCCESS);
}

int				main(void)
{
	t_env	e;

	set_env(&e);
	create_new_image(&e, W_WIDTH, W_HEIGHT);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, pointer_motion_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (EXIT_SUCCESS);
}
