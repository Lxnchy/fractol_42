/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:12:54 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/18 16:25:34 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_vars	mlx;

	ft_parse(av, ac, &mlx);
	// mlx.mlx = mlx_init();
	// mlx.win = mlx_new_window(mlx.mlx, DIM, DIM, "Hello world!");
	// mlx.img.img = mlx_new_image(mlx.mlx, DIM, DIM);
	// mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length,
	// &mlx.img.endian);
	
	// mlx.ref = (t_ref){-2, 2, -2, 2};
	// ft_fractal(&mlx.img, mlx.ref, 1, (t_complex){-0.67, 0.209});
	// mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	// mlx_hook(mlx.win, 2, 1L<<0, ft_key_hook, &mlx);
	// mlx_hook(mlx.win, 17, 1L<<17, ft_close, &mlx);
	// mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	// mlx_loop(mlx.mlx);
	return(0);
}
