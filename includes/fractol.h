/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:13:56 by jehubert          #+#    #+#             */
/*   Updated: 2023/02/18 15:08:48 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/includes/libft.h"
#include <math.h>

typedef struct s_complex	t_complex;

struct s_complex
{
	float	re;
	float	img;
	float	mod;
};

#endif