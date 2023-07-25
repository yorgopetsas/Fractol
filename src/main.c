/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/25 17:23:35 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	yz_asgn(t_mlx *d)
{
	d->e = 0;
	d->rot = 0;
	d->z = 170.0;
	d->imax = 20.;
	if (d->njr)
		d->jr = d->njr;
	else
		d->jr = -1.1380;
	d->ji = 0.2403;
	d->clr_h = 155.;
	d->clr_s = 0.60;
	d->clr_v = 0.42;
	d->m = CLR;
	d->padx = 0.;
	d->pady = 0.;
}

void	init_win(t_mlx *mx)
{
	yz_asgn(mx);
	mx->mlx = mlx_init();
	mx->win = mlx_new_window(mx->mlx, WW, HH, TITLE);
	mlx_expose_hook(mx->win, expose_hook, mx);
	mlx_hook(mx->win, 17, 0, close_hook, mx);
	mlx_hook(mx->win, 2, 0, key_hook, mx);
	mlx_mouse_hook(mx->win, mouse_hook, mx);
	mlx_do_key_autorepeaton(mx->mlx);
	mlx_loop(mx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx			mx;

	if (argc < 2)
		return (yz_error(0));
	else if (argc == 2 && yz_check(&mx, argv, argc) > 0)
		return (yz_error(2));
	else if (argc == 3 && yz_check(&mx, argv, argc) > 0)
	{
		if (yz_check(&mx, argv, argc) == 5)
			yz_error(5);
		else
			yz_error(3);
	}
	else if (argc > 3)
		yz_error(3);
	else
		init_win(&mx);
	return (0);
}
