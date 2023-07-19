/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:24:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/20 01:30:48 by yzisis-p         ###   ########.fr       */
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

# define WW 1280
# define HH 720
# define MW 640
# define MH 360
# define MXJ -3.20
# define MNJ 3.200
# define CLR 0xC9C9C9
# define DIS_CLR 0xC0C0C0
# define TITLE "Fractol by yzisis-p v 1.0"
# define INSTRC "Type: \'./fractol Julia\' or \'./fractol Mandelbrot\'"
# define MSG1 "error: Window size must be greater than 1024 x 576."
# define MSG3 "\" isn't a valid fractal name."

typedef struct s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef struct s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct s_mlx
{
	int			e;
	int			m;
	int			x;
	int			y;
	int			sl;
	int			len;
	int			nbr;
	int			num;
	int			bpp;
	int			end;
	int			rot;
	int			clr;
	char		*addr;
	char		*nam;
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
}				t_mlx;



void		yz_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void		yz_itr_frt(t_mlx *v);
void		yz_menu(t_mlx *v);
int			yz_error(int type);
int			yz_check(t_mlx *v, char **av);

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

int			ft_hsv_to_hex(double h, double s, double v);
int			ft_rgb_to_hex(t_rgb rgb);
t_rgb		ft_hsv_to_rgb(t_hsv hsv);
t_rgb		ft_hex_to_rgb(int hex);

// LIBFT
int			ft_rand(int min, int max);
int			ft_strcmp(char *s1, char *s2);
void		ft_cpy(char *s1, char *s2);
t_hsv		ft_random_color(void);
size_t		ft_strlen(const char *s);

#endif
