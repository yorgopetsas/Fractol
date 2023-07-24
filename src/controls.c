/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/24 17:46:14 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	controls(t_mlx *v, int keycode)
{
	if (keycode == 12 && v->imax > 2)
		v->imax -= 2.;
	else if (keycode == 13)
		v->imax += 2.;
	else if (keycode == 15)
		v->rot -= 90;
	else if (keycode == 17)
		v->rot += 90;
	else if (keycode == 34)
		v->z += (v->z * 0.30);
	else if (keycode == 8)
		reset_values(v);
	else if (keycode == 31 && (v->z > 10 || v->z < -10))
		v->z -= (v->z * 0.30);
	else if (keycode == 83 && v->num != 1)
		v->num = 1;
	else if (keycode == 84 && v->num != 2)
		v->num = 2;
	else if (keycode == 85 && v->num != 3)
		v->num = 3;
	else if (keycode == 123)
		v->padx -= 70.;
}

void	controls_two(t_mlx *v, int keycode)
{
	t_hsv	hsv;

	if (keycode == 1 || keycode == 46)
	{
		if (v->m == CLR)
			v->m = DIS_CLR;
		else
			v->m = CLR;
	}
	if (keycode == 124)
		v->padx += 70.;
	else if (keycode == 126)
		v->pady -= 70.;
	else if (keycode == 125)
		v->pady += 70.;
	else if (keycode == 257 || keycode == 258)
	{
		hsv = ft_random_color();
		v->clr_h = hsv.h;
		v->clr_s = hsv.s;
		v->clr_v = hsv.v;
		v->m = DIS_CLR;
	}
}

void	reset_values(t_mlx *v)
{
	v->e = 0;
	v->rot = 0;
	v->z = 170.;
	v->padx = 0.;
	v->pady = 0.;
	v->imax = 21.;
	v->jr = -1.1380;
	v->ji = 0.2403;
	v->clr_h = 358.;
	v->clr_s = 0.80;
	v->clr_v = 0.92;
	v->m = DIS_CLR;
}
