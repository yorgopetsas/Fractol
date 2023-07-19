/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/19 17:40:51 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	error(int type)
{
	char	*str;

	if (type == 0)
		write(2, MSG0, ft_strlen(MSG0));
	else if (type == 1)
		write(2, MSG1, ft_strlen(MSG1));
	else if (type == 2)
	{
		str = "error : \n";
		write(2, str, ft_strlen(str));
		write(2, "\n", 2);
		write(2, MSG0, ft_strlen(MSG0));
		free(str);
	}
	write(2, "\n", 1);
	return (-1);
}

static int	check(t_mlx *v, char **av)
{
	ft_cpy("Julia\0", v->ftl[0]);
	ft_cpy("Mandelbrot\0", v->ftl[1]);
	if (ft_strcmp(av[1], "Julia") == 0)
		v->num = 1;
	else if (ft_strcmp(av[1], "Mandelbrot") == 0)
		v->num = 2;
	else
		return (1);
	return (0);
}

void	yz_print_bckgrnd(t_mlx *mx)
{
	int	c;
	int	c2;

	c = 0;
	c2 = 0;
	while (c2 < HH)
	{
		while (c < WW)
		{
			my_mlx_pixel_put(mx, c, c2, 0x008099020);
			c += 1;
		}
		c = 0;
		c2 += 1;
	}
}

static void	yz_asgn(t_mlx *v)
{
	v->e = 0;
	v->rot = 0;
	v->z = 170.0;
	v->padx = 0.;
	v->pady = 0.;
	v->imax = 21.;
	v->jr = -1.1380;
	v->ji = 0.2403;
	v->clr_h = 358.;
	v->clr_s = 0.80;
	v->clr_v = 0.92;
	v->m = 0.;
}

static void	init_win(t_mlx *mx)
{
	yz_asgn(mx);

	mlx_expose_hook(mx->win, expose_hook, mx);
	mlx_hook(mx->win, 6, 64, motion_hook, mx);
	mlx_hook(mx->win, 17, 0, close_hook, mx);
	mlx_hook(mx->win, 2, 0, key_hook, mx);
	mlx_mouse_hook(mx->win, mouse_hook, mx);
	mlx_do_key_autorepeaton(mx->mlx);
	mlx_loop(mx->mlx);
	exit(0);
	// user_interface_texts(mx);
	// user_interface(v);
	// draw_fractal(v);
	// mlx_do_key_autorepeaton(v->mlx);
	// yz_print_mandelbrat(mx);
}

void	yz_init_menu_str(t_menu *mu)
{
	mu->max_iterations = 60;
	mu->nx = 100;
	mu->ny = 100;
	mu->ax = 100;
	mu->ay = 120;
	mu->mx = 100;
	mu->my = 140;
	mu->color = 120;
	mu->max_iterations = 1;
}

void	yz_print_menu(t_mlx *mx)
{
	t_menu		mu;
	int		max_iterations;
	char	*text;
	t_mlx	*temp;

	temp = mx;
	text = " ";
	max_iterations = 1;
	yz_init_menu_str(&mu);
	mlx_string_put(mx->mlx, mx->win, 20, 20, 0x00888020, "NAME");
	mlx_string_put(mx->mlx, mx->win, mu.ax, mu.ay, mu.color, "AUTHOR");
	mlx_string_put(mx->mlx, mx->win, mu.mx, mu.my, mu.color, text);
}

// ORG
void	yz_mx_init(t_mlx *mx)
{
	mx->mlx = mlx_init();
	mx->win = mlx_new_window(mx->mlx, WW, HH, PROG_NAME);
	mx->img = mlx_new_image(mx->mlx, WW, HH);
	mx->addr = mlx_get_data_addr(mx->img, &mx->bits_per_pixel, &mx->line_length,
								&mx->endian);
	mx->d = mlx_get_data_addr(mx->img, &mx->bits_per_pixel, &mx->line_length,
								&mx->endian);
}

int	main(int argc, char **argv)
{
	t_var		*v;
	char		*mode;
	t_mlx		mx;

	mode = argv[1];
	v = (t_var *)malloc(sizeof(t_var));
	v->nbr = argc;
	yz_mx_init(&mx);

	// mx = (t_mlx *)malloc(sizeof(t_mlx));
	// yz_check_input(argc, mode);
	// init_win(&mx);

	if (argc != 2)
		return (error(0));
	else if (WW < 1024 || HH < 576)
		return (error(1));
	else if (check(&mx, argv) > 0)
		return (error(2));
	else
		init_win(&mx);
	return (0);
}

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