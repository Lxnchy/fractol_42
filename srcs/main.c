/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:12:54 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/13 17:43:37 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_calcul(t_complex c, t_data *img)
{
	t_complex	z;
	int			i;

	z = (t_complex){0, 0};
	i = -1;
	while (ft_mod_complex(z) < 4 && ++i < 20)
		z = ft_add_complex(ft_mul_complex(z, z), c);
	if (i == 20)
		my_mlx_pixel_put(img, c.re, c.img, 0x00FF0000);
	else
		my_mlx_pixel_put(img, c.re, c.img, 0x0000FF00);
}

static void	ft_fractal(int dim, t_data *img)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < dim)
	{
		while (++j < dim)
		{
			ft_calcul((t_complex){i, j}, img);
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 700, 700, "Hello world!");
	img.img = mlx_new_image(mlx, 700, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	ft_fractal(700, &img);
	// my_mlx_pixel_put(&img, 300, 300,0x0000FF00 );
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return(0);
}
