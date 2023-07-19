/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:24:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/19 13:10:43 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// REMOVE  ----- LIBRARY FOR PRINTF() 
# include <stdio.h>

// LIBRARY FOR READ
# include <unistd.h>

// MATH LIBRARY
# include <math.h>

// MLX LIBRARY
# include "../inc/mlx/mlx.h"

// LIBRARY FOR MALLOC() AND ARGUMENTS PARSEMENT
# include <stdlib.h>

// MLX LIBRARY ! EXCLUDE FROM SOURCE !
// #include <mlx/mlx.h>

// LIBFT
# include "../libft/include/libft.h"

# define D (double)

int			ft_hsv_to_hex(double h, double s, double v);

# define UI_DISABLE_CLR ft_hsv_to_hex(v->clr_h, v->clr_s, v->clr_v)

# define UI_CLR 0xC0C0C0

# define MIN_X v->minx
# define MIN_Y v->miny
# define MAX_X v->maxx
# define MAX_Y v->maxy

// IMAGE STRUCTS
typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		it_max;
	int		zoom;
	double	x1;
	double	y1;
	int		color;
	char	set;
}				t_mlx;

// Menu data
typedef struct	s_menu {
	// char	*name;
	// char	*author;
	double	nx;
	double	ny;
	double	ax;
	double	ay;	
	double	mx;
	double	my;
	int		color;
	int		max_iterations;
}				t_menu;

typedef struct s_fractol {
	int				isinside;
	int				color;
	double			minre;
	double			maxre;
	double			minim;
	double			maxim;
	double			re_factor;
	double			im_factor;
	double			cr;
	double			ci;
	double			zr;
	double			zr2;
	double			zi;
	double			zi2;
	unsigned int	maxiterations;
}				t_fractol;

# define WW 1280
# define HH 720

//

# define MID_W 640
# define MID_H 360

# define MIN_J -3.20
# define MAX_J 3.200

# define PROG_NAME "Fractol by yzisis-p"

# define MSG0 "usage: ./fractol (Julia / Mandelbrot)"
# define MSG1 "error: Window size must be greater than 1024 x 576."
# define MSG3 "\" isn't a valid fractal name."

void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

int			expose_hook(t_var *v);
int			key_hook(int keycode, t_var *v);
int			close_hook(int button, t_var *v);
int			mouse_hook(int button, int x, int y, t_var *v);
int			motion_hook(int x, int y, t_var *v);

int			put_pixel(t_var *v, int type);
void		draw_fractal(t_var *v);
void		user_interface(t_var *v);
void		user_interface_texts(t_var *v);

void		yz_mlx_draw(t_var *v, int x, int y, int clr);

void		fractal_julia(t_var *v);
void		fractal_mandelbrot(t_var *v);
void		rotate_fractal(t_var *v, int rot);

void		controls_part_one(t_var *v, int keycode);
void		controls_part_two(t_var *v, int keycode);
void		reset_values(t_var *v);

t_rgb		ft_hsv_to_rgb(t_hsv hsv);
t_rgb		ft_hex_to_rgb(int hex);
int			ft_rgb_to_hex(t_rgb rgb);
int			ft_shade_color(int clr, double val);
// t_percent	ft_rgb_to_percent(t_rgb rgb);


// LIBFT
size_t		ft_strlen(const char *s);
void		ft_cpy(char *s1, char *s2);
t_hsv		ft_random_color(void);
int			ft_rand(int min, int max);

// NEW
void		yz_print_mandelbrat(t_mlx *mx);
void		yz_mandel_calc(t_fractol *fm, t_mlx *mx);
void		man_calc_two(t_fractol *fm, unsigned int n);
void		man_calc_one(t_fractol *fm, unsigned int x);
void		yz_init_mandelbrot_struct(t_fractol *fm);


#endif





// void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
// void	yz_print_mandelbrat(t_mlx *mx);
// int		yz_mouse_hook(int keycode, t_mlx *mx);
// int		yz_key_hook(int keycode, t_mlx *mx);
// MENU
// void	yz_print_menu(t_mlx *mx);


// TEMP
// void	mandelbrot_init(t_mlx *data);
// void	*mandelbrot(void *tab);

// # define WW 500
// # define HH 500

// typedef struct s_hsv
// {
// 	double		h;
// 	double		s;
// 	double		v;
// }				t_hsv;

// typedef struct s_percent
// {
// 	double		r;
// 	double		g;
// 	double		b;
// }				t_percent;

// typedef struct s_rgb
// {
// 	double		r;
// 	double		g;
// 	double		b;
// }				t_rgb;


// typedef struct s_var
// {
// 	int			e;
// 	int			m;
// 	int			x;
// 	int			y;
// 	int			sl;
// 	int			len;
// 	int			nbr;
// 	int			num;
// 	int			bpp;
// 	int			end;
// 	int			rot;
// 	int			clr;
// 	char		*d;
// 	char		*nam;
// 	char		ftl[3][12];
// 	float		minx;
// 	float		miny;
// 	double		i;
// 	double		z;
// 	double		imax;
// 	double		padx;
// 	double		pady;
// 	double		clr_h;
// 	double		clr_s;
// 	double		clr_v;
// 	long double	jr;
// 	long double	ji;
// 	long double	mr;
// 	long double	mi;
// 	long double	zr;
// 	long double	zi;
// 	long double	tmp;
// 	long double	mod;
// 	void		*img;
// 	void		*mlx;
// 	void		*win;
// }				t_var;