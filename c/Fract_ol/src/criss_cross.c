/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:18:38 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/29 11:36:44 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

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


double		module_i(double x, double y)
{
	return ((x * x + y * y));
}

int			fractal_julia(int x, int y, t_env *e)
{
	int		color;
	double	coord_x;
	double	coord_y;
	double	a;
	double	b;
	int		i;

	color = 0xeeeeee;
	coord_x = (double)x - (W_WIDTH / 2 + e->origin->x) * e->zoom;
	coord_y = (double)y - (W_HEIGHT / 2 + e->origin->y) * e->zoom;
	a = 
	return (color);
}

void		criss_cross(t_env *e, int (*ft)(double, double, t_pt *))
{
	int			x;
	int			y;
	int			color;

	x = 0;
	while (x != W_WIDTH)
	{
		y = 0;
		while (y != W_HEIGHT)
		{
			color = ft(x, y, e);
			my_pixel_put_to_image(e->img, x, y, color);
			y++;
		}
		x++;
	}
}


