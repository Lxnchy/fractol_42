/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:07:07 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/18 16:29:43 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_bad_digit(void)
{
	ft_printf("L'une des coordonnees n'est pas correct.\n");
	ft_printf("Une coordonnes doit avoir la forme suivante : 1.024 (exemple)\n");
	exit(1);
}

static void	ft_sign(char **ptr, int *sign)
{
	if (**ptr == '-')
	{
		*sign = -1.0;
		(*ptr)++;
		return ;
	}
	else if (**ptr == '+')
	{
		*sign = 1.0;
		(*ptr)++;
		return ;
	}
	else if (!ft_isdigit(**ptr))
		ft_bad_digit();
	*sign = 1;
}

double long	ft_atof(char *ptr)
{
	double long		result;
	double long		fraction;
	int				sign;

	result = 0.0;
	sign = 1.0;
	ft_sign(&ptr, &sign);
	while (ft_isdigit(*ptr))
	{
		result = result * 10.0 + (*ptr - '0');
		ptr++;
	}
	if (*ptr == '.')
	{
		ptr++;
		fraction = 1.0;
		while (ft_isdigit(*ptr))
		{
			fraction /= 10.0;
			result += (*ptr - '0') * fraction;
			ptr++;
		}
	}
	return (result * sign);
}
