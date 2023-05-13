/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:13:56 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/13 17:31:47 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct s_complex	t_complex;
typedef struct s_data		t_data;

struct s_complex
{
	long double	re;
	long double	img;
};

struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

/* COMPLEX */

t_complex	ft_new_complex(long double re, long double img);
t_complex	ft_mul_complex(t_complex a, t_complex b);
long double	ft_mod_complex(t_complex z);
t_complex	ft_add_complex(t_complex a, t_complex b);

/* MLX */

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif