/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:24:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/25 01:41:18 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// LIBRARY FOR READ
# include <unistd.h>
// MATH LIBRARY
# include <math.h>
// MLX LIBRARY
# include "../inc/mlx/mlx.h"
// LIBRARY FOR MALLOC() AND ARGUMENTS PARSEMENT
# include <stdlib.h>
# include <stdio.h>

// LIBRARY for strlen
# include <string.h>

# define WW 1278
# define HH 718
# define MW 640
# define MH 360
# define MXJ -3.20
# define MNJ 3.200
# define CLR 0xC1C1C1
# define DIS_CLR 0xC0C0C0

# define TITLE "Fractol (v1.0) by yzisis-p"
# define INSTRC "Please Type: \'./fractol Julia\' or \'./fractol Mandelbrot\'"
# define INSTRC2 "Name Misspeld. Should be: \'Julia\' or \'Mandelbrot\'"

typedef struct s_rgb
{
	int		num_colors;
	double	hue;
	double	saturation;
	double	value;
	double	c;
	double	red;
	double	green;
	double	blue;
	double	x;
	double	m;
}				t_rgb;

typedef struct s_mlx
{
	int			e;
	int			m;
	int			x;
	int			y;
	int			sl;
	int			num;
	int			rot;
	int			clr;
	char		ftl[3][12];
	float		minx;
	float		miny;
	double		i;
	double		z;
	double		imax;
	double		padx;
	double		pady;
	double		clr_h;
	double		clr_s;
	double		clr_v;
	long double	jr;
	long double	ji;
	long double	mr;
	long double	mi;
	long double	zr;
	long double	zi;
	long double	tmp;
	long double	mod;
	void		*img;
	void		*mlx;
	void		*win;
	int			bpp;
	int			end;
	char		*addr;
	double		njr;
}				t_mlx;

void		mlx_int_str_to_wordtab(char *str);

void		yz_itr_frt(t_mlx *v);
void		yz_menu(t_mlx *v);
int			yz_error(int type);
int			yz_check(t_mlx *v, char **av);

double		yz_string_double(char *argv);
double		yz_calc_result(char *argv, int *decd, int decs, int sign);
double		yz_countdown(double result2, int *decd);
int			yz_check_sign(char *argv);

int			yz_coloring(t_mlx *v);

int			expose_hook(t_mlx *v);
int			motion_hook(int x, int y, t_mlx *v);
int			key_hook(int keycode, t_mlx *v);
int			mouse_hook(int button, int x, int y, t_mlx *v);
int			close_hook(int button, t_mlx *v);

void		fractal_mandelbrot(t_mlx *v);
void		fractal_julia(t_mlx *v);
void		rotate_fractal(t_mlx *v, int rot);

void		controls(t_mlx *v, int keycode);
void		controls_two(t_mlx *v, int keycode);
void		reset_values(t_mlx *v);

int			ft_strcmp(char *s1, char *s2);
void		ft_cpy(char *s1, char *s2);

size_t		ft_strlen(const char *s);

#endif

// int			ft_rand(int min, int max);
// void		yz_mlx_pixel_put(t_mlx *data, int x, int y, int color);
