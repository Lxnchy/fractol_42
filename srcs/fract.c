/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:59:29 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/19 03:07:01 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_pix(t_point p, t_vars *mlx)
{
	t_complex	z;
	t_complex	c;
	int			i;

	if (!mlx->fract)
	{
		z = (t_complex){0, 0};
		c = p.calc;
	}
	else
	{
		z = p.calc;
		c = mlx->julia;
	}
	i = -1;
	while (ft_mod_complex(z) < 4 && ++i < MAXITER)
		z = ft_add_complex(ft_mul_complex(z, z), c);
	if (i == MAXITER)
		my_mlx_pixel_put(&mlx->img, p.pos.re, p.pos.img, 0);
	else
		my_mlx_pixel_put(&mlx->img, p.pos.re, p.pos.img,
			ft_color(i, mlx->fr, mlx->fg, mlx->fb));
}

static t_complex	ft_point(int px, int py, t_ref ref)
{
	double long	x;
	double long	y;

	x = ref.xmin + ((ref.xmax - ref.xmin) / DIM) * px;
	y = ref.ymin + ((ref.ymax - ref.ymin) / DIM) * py;
	return ((t_complex){x, y});
}

void	ft_fractal(t_vars *mlx)
{
	double long	i;
	double long	j;
	t_point		tmp;

	i = -1.0;
	while (++i < DIM)
	{
		j = -1.0;
		while (++j < DIM)
		{
			tmp = (t_point){(t_complex){i, j}, ft_point(i, j, mlx->ref)};
			ft_pix(tmp, mlx);
		}
	}
}
