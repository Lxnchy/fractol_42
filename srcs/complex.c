/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:43:17 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/18 15:17:21 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	ft_mul_complex(t_complex *a, t_complex *b)
{
	t_complex	res;
	int			re;
	int			img;

	re = (a->re * b->re) - (a->img * b->img);
	img = (a->re * b->img + b->re * a->img);
	res.img = img;
	res.re = re;
	res.mod = sqrt(pow(res.re, 2) + pow(res.img, 2));
	return (res);
}

t_complex	*ft_new_complex(float re, float img)
{
	t_complex	*new;

	new = malloc(sizeof(t_complex));
	if (!new)
		return (NULL);
	new->re = re;
	new->img = img;
	new->mod = sqrt(pow(new->re, 2) + pow(new->img, 2));
}