/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorgopetsas <yorgopetsas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/24 14:40:40 by yorgopetsas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	yz_asgn(t_mlx *d)
{
	d->e = 0;
	d->rot = 0;
	d->z = 170.0;
	d->padx = 0.;
	d->pady = 0.;
	d->imax = 21.;
	d->jr = -1.1380;
	d->ji = 0.2403;
	d->clr_h = 158.;
	d->clr_s = 0.60;
	d->clr_v = 0.42;
	d->m = 0.;
	d->color = 265;
}

static void	init_win(t_mlx *mx)
{
	yz_asgn(mx);
	mx->mlx = mlx_init();
	mx->win = mlx_new_window(mx->mlx, WW, HH, TITLE);
	mx->img = mlx_new_image(mx->mlx, WW, HH);
	mlx_expose_hook(mx->win, expose_hook, mx);
	mlx_hook(mx->win, 6, 64, motion_hook, mx);
	mlx_hook(mx->win, 17, 0, close_hook, mx);
	mlx_hook(mx->win, 2, 0, key_hook, mx);
	mlx_mouse_hook(mx->win, mouse_hook, mx);
	mlx_do_key_autorepeaton(mx->mlx);
	mlx_loop(mx->mlx);
	// exit(0);
}

int	main(int argc, char **argv)
{
	char		*mode;
	t_mlx		mx;

	mode = argv[1];
	// mx = (t_mlx)malloc(sizeof(t_mlx));

	if (argc < 2)
		return (yz_error(0));
	else if (yz_check(&mx, argv) > 0)
		return (yz_error(2));
	else
		init_win(&mx);
	return (0);
}
