
// int			expose_hook(t_var *v);
// int			motion_hook(int x, int y, t_var *v);
// int			key_hook(int keycode, t_var *v);
// int			close_hook(int button, t_var *v);
// int			mouse_hook(int button, int x, int y, t_var *v);
// void		yz_mlx_draw(t_var *v, int x, int y, int clr);
// void		user_interface(t_var *v);
// void		user_interface_texts(t_var *v);
// t_percent	ft_rgb_to_percent(t_rgb rgb);
// void		draw_fractal(t_var *v);
// void		fractal_mandelbrot(t_var *v);
// void		fractal_julia(t_var *v);
// void		rotate_fractal(t_var *v, int rot);
// void		my_mlx_pixel_put(t_var *data, int x, int y, int color);

// void		controls_part_one(t_var *v, int keycode);
// void		controls_part_two(t_var *v, int keycode);
// void		reset_values(t_var *v);

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




// ORG
// void	yz_mx_init(t_mlx *mx)
// {
// 	// mx->mlx = mlx_init();
// 	// mx->win = mlx_new_window(mx->mlx, WW, HH, PROG_NAME);
// 	// mx->img = mlx_new_image(mx->mlx, WW, HH);
// 	// mx->addr = mlx_get_data_addr(mx->img, &mx->bits_per_pixel, &mx->line_length,
// 	// 							&mx->endian);
// 	// mx->d = mlx_get_data_addr(mx->img, &mx->bits_per_pixel, &mx->line_length,
// 	// 							&mx->endian);
// }



	// yz_check_input(argc, mode);
	// init_win(&mx);

	// v->mlx = mlx_init();
	// v->win = mlx_new_window(v->mlx, WW, HH, PROG_NAME);
	// v->img = mlx_new_image(v->mlx, WW, HH);
	// v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	// v->addr = mlx_get_data_addr(v->img, &v->bits_per_pixel, &v->line_length,
	// 						&v->endian);
	
/////////////////////////////
	// mlx_string_put(mx.mlx, mx.win, 100, 100, 0x00888020, "NAME");
// int	yz_check_input(int argc, char *set)
// {
// 	if (argc < 2)
// 	{
// 		printf("Please select a set: 'm' for Mandelbrot and 'j' for Julia.\n");
// 		return (0);
// 	}
// 	if (set[0] == 'j' || set[0] == 'm')
// 		return (1);
// 	else
// 		return (0);
// }


		// my_mlx_pixel_put(&v, 20, 20, 0x00998020);
	// my_mlx_pixel_put(&v, 21, 20, 0x00998020);
	// my_mlx_pixel_put(&v, 22, 20, 0x00998020);
	// my_mlx_pixel_put(&v, 23, 20, 0x00998020);


// static void	init_win(t_var *v)
// {
// 	yz_asgn(v);
// 	v->mlx = mlx_init();
// 	v->win = mlx_new_window(v->mlx, WW, HH, PROG_NAME);
// 	v->img = mlx_new_image(v->mlx, WW, HH);
// 	// v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
// 	v->addr = mlx_get_data_addr(v->img, &v->bits_per_pixel, &v->line_length,
// 							&v->endian);

// 	// user_interface_texts(v);
// 	// user_interface(v);

// 	// my_mlx_pixel_put(v, 21, 20, 0x00998020);

// 	mlx_expose_hook(v->win, mlx_expose_hook, v);
// 	mlx_hook(v->win, 6, 64, motion_hook, v);
// 	mlx_hook(v->win, 17, 0, close_hook, v);
// 	mlx_hook(v->win, 2, 0, key_hook, v);
// 	mlx_mouse_hook(v->win, mouse_hook, v);
// 	draw_fractal(v);
// 	mlx_do_key_autorepeaton(v->mlx);
// 	mlx_loop(v->mlx);

// 	// exit(0);

// }

/////////////////////////
// OLD BELOW 
// void	yz_mx_init(t_mlx *mx)
// {
// 	mx->mlx = mlx_init();
// 	mx->win = mlx_new_window(mx->mlx, WW, HH, "Fractol by Dubby");
// 	mx->img = mlx_new_image(mx->mlx, WW, HH);
// 	mx->addr = mlx_get_data_addr(mx->img, &mx->bits_per_pixel, &mx->line_length,
// 								&mx->endian);
// }

// int	yz_check_input(int argc, char *set)
// {
// 	if (argc < 2)
// 	{
// 		printf("Please select a set: 'm' for Mandelbrot and 'j' for Julia.\n");
// 		return (0);
// 	}
// 	if (set[0] == 'j' || set[0] == 'm')
// 		return (1);
// 	else
// 		return (0);
// }


// void			fractal_mandelbrot(t_mlx *v)
// {
// 	v->i = -2.0;

// 	v->zr = 0.0;
// 	v->zi = 0.0;

// 	// v->rot = -2;

// 	if (v->num == 2) {
// 		v->rot = 2;
// 	} else {
// 		v->rot = -2;
// 	}
// 	v->mr = (v->e == 0 || v->e == 2) ? (D(v->x) / v->z) + v->minx :
// 	(D(v->y) / v->z) + v->miny;
// 	v->mi = (v->e == 0 || v->e == 2) ? (D(v->y) / v->z) + v->miny :
// 	(D(v->x) / v->z) + v->minx;
// 	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
// 	{
// 		v->tmp = v->zr;
// 		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->mr;
// 		v->zi = v->mod * v->zi * v->tmp + v->mi;
// 	}
// 	v->clr = edit_hue_hex(v);
// 	if (((v->x >= 25 && v->x <= 188) &&
// 	((v->y >= 25 && v->y <= 213) || (v->y >= 237 && v->y <= 326) ||
// 	(v->y >= (HH - 133) && v->y <= (HH - 25)))) ||
// 	(v->x >= (v->len - 1) && v->x <= (WW - 25) &&
// 	v->y >= (HH - 65) && v->y <= (HH - 25)))
// 		v->clr = ft_shade_color(v->clr, 0.35);
// 	// put_pixel(v, 0);
// 	mlx_pixel_put(v->mlx, v->win, v->x, v->y, v->clr + v->x);
// }





		// if (keycode == 18)
		// {
		// 	yz_print_mandelbrat(v);
		// }
		// else if (keycode == 19)
		// {
		// 	yz_print_bckgrnd(v);
		// }

// int		expose_hook(t_mlx *v)
// {
// 	t_mlx *g;
// 	int tmp;
	
// 	g = v;
	

// 	tmp = 0;
	
// 	printf("%i", tmp);
// 	// mlx_string_put(v->mlx, v->win, 100, 100, 0x00888020, "NAME");
// 	// yz_print_mandelbrat(v);
// 	// v->img = mlx_new_image(v->mlx, WW, HH);
// 	// v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
// 	// draw_fractal(v);
// 	// user_interface(v);
// 	// mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
// 	// user_interface_texts(v);
// 	return (0);
// }

// int	expose_hook(t_var *v)
// {
// 	// v->img = mlx_new_image(v->mlx, WW, HH);
// 	// v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
// 	// draw_fractal(v);
// 	// user_interface_texts(v);
// 	// No Imprime
// 	mlx_string_put(v->mlx, v->win, 100, 100, 0x00888020, "NAME");
// 	// user_interface(v);
// 	// mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);

	
// 	return (0);
// }

	
	// v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	// v->d = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	// user_interface(v);
	// yz_print_mandelbrat(v);
	// yz_print_bckgrnd(v);
	

	// if (v->num == 4)
	// {
	// 	mlx_string_put(v->mlx, v->win, 20, 20, 0x00888020, "MANDELBROT");
	// }
	// mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	// mlx_pixel_put(v->mlx, v->win, 20, 20, 0x008099020);



// void	yz_mlx_draw(t_mlx *v, int x, int y, int clr)
// {
// 	int	tmp1;
// 	int	tmp2;

// 	tmp1 = v->x;
// 	tmp2 = v->y;
// 	v->clr = ft_shade_color(clr, 0.20);
// 	while (v->x <= x && mlx_pixel_put(v->mlx, v->win, x, y, 0x00888020) == 0)
// 		v->x++;
// 	while (v->y <= y && mlx_pixel_put(v->mlx, v->win, x, y, 0x00888020) == 0)
// 		v->y++;
// 	while (v->x > tmp1 && mlx_pixel_put(v->mlx, v->win, x, y, 0x00888020) == 0)
// 		v->x--;
// 	while (v->y > tmp2 && mlx_pixel_put(v->mlx, v->win, x, y, 0x00888020) == 0)
// 		v->y--;
// }


// int		put_pixel(t_mlx *v, int type)
// {
// 	int		i;
// 	int		x;
// 	int		y;
// 	char	*rgb;

// 	x = v->x;
// 	y = v->y;

// 	i = type;
// 	rgb = "hola";
// 	if (((type == 1 && x > 213) || (type != 1 && x >= 0))
// 			&& x < WW && y >= 0 && y < HH)
// 	{
// 		i = ((int)v->x * (v->bits_per_pixel / 8)) + ((int)v->y * v->sl);
// 		rgb = (char*)&v->clr;
// 		v->d[i] = rgb[0];
// 		v->d[++i] = rgb[1];
// 		v->d[++i] = rgb[2];
// 	}
// 	return (0);
// }


// int	yz_key_hook(int keycode, t_mlx *mx)
// {
// 	t_mlx	*y;

// 	y = mx;
// 	printf("%d\n", keycode);
// 	if (keycode == 53)
// 	{
// 		printf("OOOPS, somebody pressed 'ESC'.\nThe Window is Closing.\n");
// 		// mlx_destroy_image(mx->mlx, mx->win);
// 		// mlx_destroy_window(mx->mlx, mx->win);
// 		exit (0);
// 	}
// 	return (0);
// }

// int	yz_mouse_hook(int keycode, t_mlx *mx)
// {
// 	t_mlx	*y;

// 	y = mx;
// 	printf("%d\n", keycode);
// 	if (keycode == 53)
// 	{
// 		printf("OOOPS, somebody pressed 'ESC'.\nThe Window is Closing.\n");
// 		exit (0);
// 	}
// 	return (0);
// }

// My Put Pixel Function
// void	my_mlx_pixel_put(t_var *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }


// void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }



// t_hsv		ft_random_color(void)
// {
// 	t_hsv	hsv;

// 	hsv.h = ((double)ft_rand(0, 3600) / 10.0);
// 	hsv.s = ((double)ft_rand(740, 810) / 1000.0);
// 	hsv.v = ((double)ft_rand(800, 950) / 1000.0);
// 	return (hsv);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/19 23:16:58 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	ft_cpy(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s1[++i] != 0)
		s2[i] = s1[i];
	s2[i] = 0;
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int			put_pixel(t_mlx *v, int type);

// int	put_pixel(t_mlx *v, int type)
// {
// 	int		i;
// 	int		x;
// 	int		y;
// 	char	*rgb;

// 	x = v->x;
// 	y = v->y;
// 	if (((type == 1 && x > 213) || (type != 1 && x >= 0))
// 			&& x < WW && y >= 0 && y < HH)
// 	{
// 		i = ((int)v->x * (v->bpp / 8)) + ((int)v->y * v->sl);
// 		rgb = (char*)&v->clr;
// 		v->d[i] = rgb[0];
// 		v->d[++i] = rgb[1];
// 		v->d[++i] = rgb[2];
// 	}
// 	return (0);
// }