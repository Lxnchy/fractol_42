/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:48:59 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/18 17:19:49 by jehubert         ###   ########.fr       */
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
	mlx->ref.xmin = r.xmin - 0.015 * r.xmin + nx;
	mlx->ref.xmax = r.xmax - 0.015 * r.xmax + nx;
	mlx->ref.ymin = r.ymin - 0.015 * r.ymin + ny;
	mlx->ref.ymax = r.ymax - 0.015 * r.ymax + ny;
	ft_fractal(&mlx->img, mlx->ref, mlx->fract, mlx->julia);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}