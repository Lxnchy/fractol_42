/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:59:29 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/18 19:17:02 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_pix(t_point p, t_data *img, int fract, t_complex julia)
{
	t_complex	z;
	t_complex	c;
	int			i;

	if (!fract)
	{
		z = (t_complex){0, 0};
		c = p.calc;
	}
	else
	{
		z = p.calc;
		c = julia;
	}
	i = -1;
	while (ft_mod_complex(z) < 4 && ++i < MAXITER)
		z = ft_add_complex(ft_mul_complex(z, z), c);
	if (i == MAXITER)
		my_mlx_pixel_put(img, p.pos.re, p.pos.img, 0);
	else
		my_mlx_pixel_put(img, p.pos.re, p.pos.img, 0x0000FF00);
}

static t_complex	ft_point(int px, int py, t_ref ref)
{
	double long	x;
	double long	y;

	x = ref.xmin + ((ref.xmax - ref.xmin) / DIM) * px;
	y = ref.ymin + ((ref.ymax - ref.ymin) / DIM) * py;
	return ((t_complex){x, y});
}

void	ft_fractal(t_data *img, t_ref ref, int fract, t_complex julia)
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
			tmp = (t_point){(t_complex){i, j}, ft_point(i, j, ref)};
			ft_pix(tmp, img, fract, julia);
		}
	}
}
