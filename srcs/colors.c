/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 03:06:44 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/19 03:06:44 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_color(int n, int fr, int fg, int fb)
{
	int	r;
	int	g;
	int	b;

	r = n * fr % 255;
	g = n * fg % 255;
	b = n * fb % 255;
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	ft_update_color(t_vars *mlx)
{
	static int	i = 0;

	if (!i)
	{
		mlx->fr = 4;
		mlx->fg = 20;
		mlx->fb = 12;
	}
	if (i == 1)
	{
		mlx->fr = 9;
		mlx->fg = 1;
		mlx->fb = 17;
	}
	if (i == 2)
	{
		mlx->fr = 21;
		mlx->fg = 9;
		mlx->fb = 7;
		i = -1;
	}
	i++;
	ft_fractal(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
