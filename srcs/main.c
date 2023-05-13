/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:12:54 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/13 18:08:45 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_pix(t_complex c, t_data *img, int dim)
{
	t_complex	z;
	int			i;

	z = (t_complex){0, 0};
	i = -1;
	while (ft_mod_complex(z) < 4 && ++i < 200)
		z = ft_add_complex(ft_mul_complex(z, z), c);
	if (i == 20)
		my_mlx_pixel_put(img, c.re + dim / 2, c.img + dim / 2, 0x00FF0000);
	else
		my_mlx_pixel_put(img, c.re + dim / 2, c.img + dim / 2, 0x0000FF00);
}

static void	ft_fractal(int dim, t_data *img)
{
	int	i;
	int	j;

	i = -dim / 2 - 1;
	j = -dim / 2 - 1;
	while (++i < dim / 2)
		while (++j < dim / 2)
			ft_pix((t_complex){i, j}, img, dim);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		dim;

	dim = 700;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, dim, dim, "Hello world!");
	img.img = mlx_new_image(mlx, dim, dim);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	ft_fractal(dim, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return(0);
}
