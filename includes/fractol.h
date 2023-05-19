/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:13:56 by jehubert          #+#    #+#             */
/*   Updated: 2023/05/19 03:08:55 by jehubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>

# define M_XMIN -2.2
# define M_YMIN -1.5
# define M_XMAX 0.8
# define M_YMAX 1.5
# define J_XMIN -1
# define J_YMIN -1
# define J_XMAX 1
# define J_YMAX 1
# define DIM 1000
# define MAXITER 20

typedef struct s_complex	t_complex;
typedef struct s_data		t_data;
typedef struct s_point		t_point;
typedef struct s_vars		t_vars;
typedef struct s_ref		t_ref;

struct s_ref
{
	long double	xmin;
	long double	xmax;
	long double	ymin;
	long double	ymax;
};

struct s_complex
{
	long double	re;
	long double	img;
};

struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_point {
	t_complex	pos;
	t_complex	calc;
};

struct	s_vars {
	void		*mlx;
	void		*win;
	t_ref		ref;
	t_complex	julia;
	int			fract;
	int			fr;
	int			fg;
	int			fb;
	t_data		img;
};

/* COMPLEX */

t_complex	ft_new_complex(long double re, long double img);
t_complex	ft_mul_complex(t_complex a, t_complex b);
long double	ft_mod_complex(t_complex z);
t_complex	ft_add_complex(t_complex a, t_complex b);

/* MLX */

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_key_hook(int keycode, t_vars *mlx);
int			ft_mouse_hook(int keycode, int x, int y, t_vars *mlx);
int			ft_close(t_vars *mlx);

/* ATOF */

double long	ft_atof(char *str);

/* FRACT */

// void		ft_fractal(t_data *img, t_ref ref, int fract, t_complex julia);
void		ft_fractal(t_vars *mlx);

/* PARSING */

void		ft_parse(char **av, int ac, t_vars *mlx);

/* ZOOM */

void		ft_zoom(t_vars *mlx, int x, int y);
void		ft_dezoom(t_vars *mlx, int x, int y);
void		ft_move(t_vars *mlx, char *move);

/* COLORS */

int			ft_color(int n, int fr, int fg, int fb);
void		ft_update_color(t_vars *mlx);

#endif
