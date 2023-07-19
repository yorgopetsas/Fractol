/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/19 23:12:05 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	v->clr_h = 258.;
	v->clr_s = 0.40;
	v->clr_v = 0.52;
	v->m = 0.;
}

static void	init_win(t_mlx *mx)
{
	yz_asgn(mx);
	mx->mlx = mlx_init();
	mx->win = mlx_new_window(mx->mlx, WW, HH, PROG_NAME);
	mx->img = mlx_new_image(mx->mlx, WW, HH);
	mlx_expose_hook(mx->win, expose_hook, mx);
	mlx_hook(mx->win, 6, 64, motion_hook, mx);
	mlx_hook(mx->win, 17, 0, close_hook, mx);
	mlx_hook(mx->win, 2, 0, key_hook, mx);
	mlx_mouse_hook(mx->win, mouse_hook, mx);
	mlx_do_key_autorepeaton(mx->mlx);
	mlx_loop(mx->mlx);
	exit(0);
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

int	main(int argc, char **argv)
{
	t_var		*v;
	char		*mode;
	t_mlx		*mx;

	mode = argv[1];
	v = (t_var *)malloc(sizeof(t_var));
	mx = (t_mlx *)malloc(sizeof(t_var));
	mx->nbr = argc;
	v->nbr = argc;

	// yz_mx_init(mx);

	if (argc != 2)
		return (yz_error(0));
	else if (WW < 1024 || HH < 576)
		return (yz_error(1));
	else if (yz_check(mx, argv) > 0)
		return (yz_error(2));
	else
		init_win(mx);
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

