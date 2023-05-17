/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:09:45 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/17 18:19:51 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close(t_vars *mlx)
{
	mlx_destroy_image(mlx->mlx, (mlx->img).img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

int	ft_key_hook(int keycode, t_vars *mlx)
{
	if (keycode == 65307)
		ft_close(mlx);
	else if (keycode == 115)
		ft_printf("Change color\n");
	else if (keycode == 65362)
		ft_printf("Move 10% up\n");
	else if (keycode == 65361)
		ft_printf("Move 10% left\n");
	else if (keycode == 65364)
		ft_printf("Move 10% down\n");
	else if (keycode == 65363)
		ft_printf("Move 10% right\n");
	return (0);
}

int	ft_mouse_hook(int keycode, int x, int y, t_vars *mlx)
{
	printf("px: %i ; py: %i ; x: %f ; y: %d\n", x, y, XMIN + ((XMAX - XMIN) / DIM) * x, 0);
	if (keycode == 4)
		ft_printf("ZOOM\n");
	else if (keycode == 5)
		ft_printf("DEZOOM\n");
	(void)mlx;
	return (0);
}
