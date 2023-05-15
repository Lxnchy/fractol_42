/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:13:56 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/15 16:48:35 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>

# define xmin -2
# define ymin -2
# define xmax 1.5
# define ymax 1.5
# define DIM 800

typedef struct s_complex	t_complex;
typedef struct s_data		t_data;
typedef	struct s_point		t_point;

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

struct s_point {
	t_complex	pos;
	t_complex	calc;
};

/* COMPLEX */

t_complex	ft_new_complex(long double re, long double img);
t_complex	ft_mul_complex(t_complex a, t_complex b);
long double	ft_mod_complex(t_complex z);
t_complex	ft_add_complex(t_complex a, t_complex b);

/* MLX */

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif