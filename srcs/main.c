/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:12:54 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/17 17:12:15 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_pix(t_point p, t_data *img)
{
	t_complex	z;
	int			i;

	z = (t_complex){0, 0};
	i = -1;
	while (ft_mod_complex(z) < 4 && ++i < maxiter)
		z = ft_add_complex(ft_mul_complex(z, z), p.calc);
	if (i == maxiter)
		my_mlx_pixel_put(img, p.pos.re, p.pos.img, 0);
	else
		my_mlx_pixel_put(img, p.pos.re, p.pos.img, 0x0000FF00);
}

static t_complex	ft_point(int px, int py)
{
	double long	x;
	double long y;

	x = xmin + ((xmax - xmin) / DIM) * px;
	y = ymin + ((ymax - ymin) / DIM) * py;
	return ((t_complex){x, y});
}

static void	ft_fractal(t_data *img)
{
	double long	i;
	double long	j;
	t_point	tmp;

	i = -1.0;
	while (++i < DIM)
	{
		j = -1.0;
		while (++j < DIM)
		{
			tmp = (t_point){(t_complex){i, j}, ft_point(i, j)};
			ft_pix(tmp, img);
		}
	}
}

int	main(void)
{
	t_vars	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, DIM, DIM, "Hello world!");
	mlx.img.img = mlx_new_image(mlx.mlx, DIM, DIM);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length,
	&mlx.img.endian);
	ft_fractal(&mlx.img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L<<0, ft_key_hook, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
	return(0);
}
