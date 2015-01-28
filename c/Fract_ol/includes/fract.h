/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 15:01:51 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/28 19:52:24 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H


# define W_HEIGHT	1200
# define W_WIDTH	1200

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

/*
typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;*/

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
}					t_env;

#endif
