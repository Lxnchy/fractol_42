/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:52:56 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/18 21:18:24 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_error(void)
{
	ft_printf("Mauvais arguments. Veuillez utiliser :\n");
	ft_printf("./fractol 0 pour afficher la fractale de Mandelbrot\n");
	ft_printf("./fractol 1 x y pour afficher la fractales de Julia ");
	ft_printf("correspondante aux coordonnes x et y\n");
	exit(1);
}

static void	ft_man_init(t_vars *mlx)
{
	mlx->fract = 0;
	mlx->julia = (t_complex){0, 0};
	mlx->ref = (t_ref){M_XMIN, M_XMAX, M_YMIN, M_YMAX};
}

static void	ft_julia_init(t_vars *mlx, char **av)
{
	mlx->fract = 1;
	mlx->julia = (t_complex){ft_atof(av[2]), ft_atof(av[3])};
	mlx->ref = (t_ref){J_XMIN, J_XMAX, J_YMIN, J_YMAX};
}

void	ft_parse(char **av, int ac, t_vars *mlx)
{
	if (ac < 2)
		ft_error();
	if (!ft_strncmp(av[1], "0", ft_strlen(av[1])))
	{
		if (ac != 2)
			ft_error();
		else
			ft_man_init(mlx);
	}
	else if (!ft_strncmp(av[1], "1", ft_strlen(av[1])))
	{
		if (ac != 4)
			ft_error();
		else
			ft_julia_init(mlx, av);
	}
	else
		ft_error();
}
