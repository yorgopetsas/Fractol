/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/24 22:48:36 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	controls(t_mlx *v, int keycode)
{
	if (keycode == 1 || keycode == 46)
		v->m = (v->m == CLR) ? DIS_CLR : CLR;
	else if (keycode == 12 && v->imax > 2)
		v->imax -= 3.;
	else if (keycode == 13)
		v->imax += 3.;
	else if (keycode == 15)
		v->rot -= 90;
	else if (keycode == 17)
		v->rot += 90;
	else if (keycode == 34)
	{
		v->z += (v->z * 0.30);
		v->imax += 2.;
	}
	else if (keycode == 8)
		reset_values(v);
	else if (keycode == 78 && (v->z > 10 || v->z < -10))
	{
		v->z -= (v->z * 0.30);
		v->imax -= 2.;
	}
}

void	controls_two(t_mlx *v, int keycode)
{
	// if (keycode == 83 && v->num != 1)
	// 	v->num = 1;
	// else if (keycode == 84 && v->num != 2)
	// 	v->num = 2;
	if (keycode == 123)
		v->padx -= 70.;
	else if (keycode == 124)
		v->padx += 70.;
	else if (keycode == 126)
		v->pady -= 70.;
	else if (keycode == 125)
		v->pady += 70.;
}

void	reset_values(t_mlx *d)
{
	d->e = 0;
	d->rot = 0;
	d->z = 170.0;
	d->padx = 0.;
	d->pady = 0.;
	d->imax = 20.;
	d->jr = -1.1380;
	d->ji = 0.2403;
	d->clr_h = 155.;
	d->clr_s = 0.60;
	d->clr_v = 0.42;
	d->m = DIS_CLR;
}
