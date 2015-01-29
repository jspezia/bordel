/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 15:01:51 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/29 11:36:48 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H


# define W_HEIGHT	800
# define W_WIDTH	800

# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define KEY_SHIFT	65505
# define KEY_MORE	65451
# define KEY_LESS	65453
# define KEY_SPACE	32

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include </usr/X11R6/include/X11/X.h>
#include <unistd.h>


typedef struct		s_img
{
	void			*id;
	int				width;
	int				height;
	char			*addr;
	int				bpp;
	int				lsize;
	int				endian;
}					t_img;

typedef struct		s_keys
{
	t_bool			up;
	t_bool			down;
	t_bool			right;
	t_bool			left;
}					t_keys;

typedef struct		s_pt
{
	double			x;
	double			y;
}					t_pt;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_keys			*keys;
	t_pt			*c;
	t_pt			*origin;
	int				*zoom;
}					t_env;

/*
 *		criss_cross.c
 */

void		criss_cross(t_env *e, int (*ft)(double, double, t_pt *));
int			fractal_julia(double x, double y, t_pt *c);
double		module_i(double x, double y);
void		my_pixel_put_to_image(t_img *img, int x, int y, int color);
int			key_release(int keycode, t_env *e);
t_img		*create_new_image(t_env *e, int width, int height);

#endif
