/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 19:01:09 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/29 19:09:02 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TESTS_H
# define MLX_TESTS_H

# define W_WIDTH	640
# define W_HEIGHT	400

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_env;

typedef struct	s_img
{
	t_env		*e;
	void		*id;
	int			width;
	int			height;
	char		*addr;
	int			bpp;
	int			lsize;
	int			endian;
}				t_img;

#endif
