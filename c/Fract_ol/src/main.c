/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:18:38 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/28 21:15:50 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include </usr/X11R6/include/X11/X.h>
#include "fract.h"
#include "libft.h"
#include <unistd.h>


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
	return (e);
}

t_img		*create_new_image(t_env *e, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		exit(-1);
	if (!(img->id = mlx_new_image(e->mlx, width, height)))
		exit(-1);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->id, &img->bpp,
			&img->lsize, &img->endian);
	return (img);
}

# define RANGE		0.01

int			key_release(int keycode, t_env *e)
{
	(void)e;
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_UP)
		e->c->x += RANGE;
	if (keycode == KEY_DOWN)
		e->c->x -= RANGE;
	if (keycode == KEY_RIGHT)
		e->c->y += RANGE;
	if (keycode == KEY_LEFT)
		e->c->y -= RANGE;
	if (keycode == KEY_SPACE)
	{
		printf("c = %f, %fi\n", e->c->x, e->c->y);
	}
	return (0);
}


void			my_pixel_put_to_image(t_img *img, int x, int y, int color)
{
	int				i;
	int				mask;
	char			tmp_clr;
	int				offset;

	i = 0;
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		while (i < (img->bpp / 8))
		{
			if (img->endian == 1)
				offset = img->bpp - 8 * (i + 1);
			else
				offset = 8 * i;
			mask = 0xFF << offset;
			tmp_clr = (color & mask) >> offset;
			img->addr[y * (img->lsize) + x * (img->bpp / 8) + i] = tmp_clr;
			i++;
		}
	}
}


void		clear_img(t_img *img)
{
	int		i;
	int		j;

	j = 0;
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			my_pixel_put_to_image(img, i, j, 0x000000);
			i++;
		}
		j++;
	}
}

double		module_i(double x, double y)
{
	return ((x * x + y * y));
}

int			fractal_julia(double x, double y, t_pt *c)
{
	int		color;
	double	a;
	double	b;
	int		i;

	i = 0;
	color = 0xeeeeee;
	while ((x * x + y * y) < 4 && i < 128)
	{
		a = x * x - y * y;
		b = -2 * x * y;
		x = a + c->x;
		y = b + c->y;
		color -= 0x040404;
		i++;
	}
	return (color);
}

void		display_view(t_env *e, int (*ft)(double, double, t_pt *))
{
	int		x;
	int		y;
	int		color;
	t_pt	pixel;

	x = 0;
	while (x != W_WIDTH)
	{
		y = 0;
		while (y != W_HEIGHT)
		{
			pixel.x = ((double)x - W_WIDTH / 2) / (W_WIDTH / 2);
			pixel.y = (W_HEIGHT / 2 - (double)y) / (W_HEIGHT / 2);
			color = ft(pixel.x, pixel.y, e->c);
			my_pixel_put_to_image(e->img, x, y, color);
			y++;
		}
		x++;
	}
}

int			loop_hook(t_env *e)
{
//	clear_img(e->img);
	display_view(e, &fractal_julia);
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	return (0);
}

int			main()
{
	t_env		*e;

	e = init_env();
	e->c->x = 0.615;
	e->c->y = -1.1;
	e->img = create_new_image(e, W_WIDTH, W_HEIGHT);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, &key_release, e);
	mlx_loop_hook(e->mlx, &loop_hook, e);
//	mlx_pixel_put(e->mlx,e->win,250,10,0xFFFFFF);
	mlx_loop(e->mlx);
	return (0);
}
