/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:48:59 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/18 19:01:13 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom(t_vars *mlx, int x, int y)
{
	double long	nx;
	double long	ny;
	t_ref		r;

	r = mlx->ref;
	nx = r.xmin + ((r.xmax - r.xmin) / DIM) * x;
	ny = r.ymin + ((r.ymax - r.ymin) / DIM) * y;
	mlx->ref.xmin = r.xmin + 0.3 * (nx - r.xmin);
	mlx->ref.xmax = r.xmax + 0.3 * (nx - r.xmax);
	mlx->ref.ymax = r.ymax + 0.3 * (ny - r.ymax);
	mlx->ref.ymin = r.ymin + 0.3 * (ny - r.ymin);
	ft_fractal(&mlx->img, mlx->ref, mlx->fract, mlx->julia);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	
}


void	ft_dezoom(t_vars *mlx, int x, int y)
{
	double long	nx;
	double long	ny;
	t_ref		r;

	r = mlx->ref;
	nx = r.xmin + ((r.xmax - r.xmin) / DIM) * x;
	ny = r.ymin + ((r.ymax - r.ymin) / DIM) * y;
	mlx->ref.xmin = r.xmin - 0.3 * (nx - r.xmin);
	mlx->ref.xmax = r.xmax - 0.3 * (nx - r.xmax);
	mlx->ref.ymax = r.ymax - 0.3 * (ny - r.ymax);
	mlx->ref.ymin = r.ymin - 0.3 * (ny - r.ymin);
	ft_fractal(&mlx->img, mlx->ref, mlx->fract, mlx->julia);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	
}

void	ft_move(t_vars *mlx, char *move)
{
	if (!strncmp("right", move, 4))
	{
		mlx->ref.xmax += 0.1 * (mlx->ref.xmax - mlx->ref.xmin);
		mlx->ref.xmin += 0.1 * (mlx->ref.xmax - mlx->ref.xmin);
	}
	else if (!strncmp("left", move, 4))
	{
		mlx->ref.xmax -= 0.1 * (mlx->ref.xmax - mlx->ref.xmin);
		mlx->ref.xmin -= 0.1 * (mlx->ref.xmax - mlx->ref.xmin);
	}
	else if (!strncmp("up", move, 2))
	{
		mlx->ref.ymax -= 0.1 * (mlx->ref.ymax - mlx->ref.ymin);
		mlx->ref.ymin -= 0.1 * (mlx->ref.ymax - mlx->ref.ymin);
	}
	else if (!strncmp("down", move, 4))
	{
		mlx->ref.ymax += 0.1 * (mlx->ref.ymax - mlx->ref.ymin);
		mlx->ref.ymin += 0.1 * (mlx->ref.ymax - mlx->ref.ymin);
	}
	ft_fractal(&mlx->img, mlx->ref, mlx->fract, mlx->julia);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}