/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:43:17 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/12 15:52:47 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

long double	ft_mod_complex(t_complex z)
{
	t_complex	conj;

	conj.re = z.re;
	conj.img = -z.img;
	return (ft_mul_complex(z, conj).re);
}

t_complex	ft_mul_complex(t_complex a, t_complex b)
{
	t_complex	res;
	int			re;
	int			img;

	re = (a.re * b.re) - (a.img * b.img);
	img = (a.re * b.img + b.re * a.img);
	res.img = img;
	res.re = re;
	return (res);
}

t_complex	ft_new_complex(long double re, long double img)
{
	t_complex	new;

	new.re = re;
	new.img = img;
	return (new);
}
