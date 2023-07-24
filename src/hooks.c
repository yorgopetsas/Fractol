/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/24 19:57:11 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	expose_hook(t_mlx *v)
{
	v->img = mlx_new_image(v->mlx, WW, HH);
	v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->end);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	yz_itr_frt(v);
	yz_menu(v);
	return (0);
}

int	key_hook(int keycode, t_mlx *v)
{
	int		r;

	r = 0;
	if (keycode == 53)
	{
		mlx_destroy_image(v->mlx, v->img);
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else
	{
		if (keycode >= 1 && keycode <= 123 && ++r > 0)
			controls(v, keycode);
		else if (keycode >= 124 && keycode <= 258 && ++r > 0)
			controls_two(v, keycode);
		if (r > 0)
		{
			mlx_destroy_image(v->mlx, v->img);
			mlx_clear_window(v->mlx, v->win);
			expose_hook(v);
		}
	}
	return (0);
}

int	motion_hook(int x, int y, t_mlx *v)
{
	int		tmp;

	if (x >= 0 && x < WW && y >= 0 && y < HH && v->num == 1 && v->m == CLR)
	{
		tmp = ((MXJ - MNJ) / ((double)(WW) - 0.0));
		tmp = tmp * ((double)(x) - 0.0) + MNJ;
		v->jr = tmp;
		tmp = ((MXJ - MNJ) / ((double)(WW) - 0.0));
		tmp = tmp * ((double)(y) - 0.0) + MNJ;
		v->ji = tmp;
		mlx_destroy_image(v->mlx, v->img);
		mlx_clear_window(v->mlx, v->win);
		expose_hook(v);
	}
	return (0);
}

// int		motion_hook(int x, int y, t_mlx *v)
// {
// 	if (x >= 0 && x < WW && y >= 0 && y < HH &&
// 		v->num == 1 && v->m == CLR)
// 	{
// 		v->jr = (((MXJ - MNJ) / ((double)(WW) - 0.0)) * ((double)(x) - 0.0)) + MNJ;
// 		v->ji = (((MXJ - MNJ) / ((double)(WW) - 0.0)) * ((double)(y) - 0.0)) + MNJ;
// 		mlx_destroy_image(v->mlx, v->img);
// 		mlx_clear_window(v->mlx, v->win);
// 		expose_hook(v);
// 	}
// 	return (0);
// }

int	mouse_hook(int button, int x, int y, t_mlx *v)
{
	if (v->m == CLR && x >= 0 && x < WW && y >= 0 && y < HH)
	{
		if (button == 1)
		{
			v->padx = round(((double)(MW + v->padx) - (double)(x)) * 1.30);
			v->pady = round(((double)(MH + v->pady) - (double)(y)) * 1.30);
		}
		else if (button == 2)
		{
			v->padx = round(((double)(MW + v->padx) - (double)(x)) * 0.70);
			v->pady = round(((double)(MH + v->pady) - (double)(y)) * 0.70);
		}
		if (button == 1 || button == 5)
			v->z += (v->z * 0.30);
		if ((button == 2 || button == 4) && (v->z > 10 || v->z < -10))
			v->z -= (v->z * 0.30);
		mlx_destroy_image(v->mlx, v->img);
		mlx_clear_window(v->mlx, v->win);
		expose_hook(v);
	}
	return (0);
}

int	close_hook(int button, t_mlx *v)
{
	(void)button;
	(void)v;
	exit(0);
	return (0);
}
