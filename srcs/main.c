/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:12:54 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/16 15:16:02 by jehubert         ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, DIM, DIM, "Hello world!");
	img.img = mlx_new_image(mlx, DIM, DIM);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	ft_fractal(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return(0);
}
