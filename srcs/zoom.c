/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:48:59 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/18 18:16:46 by jehubert         ###   ########.fr       */
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
	mlx->ref.xmin = r.xmin + 0.4 * (nx - r.xmin);
	mlx->ref.xmax = r.xmax + 0.4 * (nx - r.xmax);
	mlx->ref.ymax = r.ymax + 0.4 * (ny - r.ymax);
	mlx->ref.ymin = r.ymin + 0.4 * (ny - r.ymin);
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
	mlx->ref.xmin = r.xmin + 1.1 * (nx - r.xmin);
	mlx->ref.xmax = r.xmax + 1.1 * (nx - r.xmax);
	mlx->ref.ymax = r.ymax + 1.1 * (ny - r.ymax);
	mlx->ref.ymin = r.ymin + 1.1 * (ny - r.ymin);
	ft_fractal(&mlx->img, mlx->ref, mlx->fract, mlx->julia);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	
}
