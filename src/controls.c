/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/25 02:47:55 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	controls(t_mlx *v, int keycode)
{
	if (keycode == 1 || keycode == 46)
	{
		if (v->m == CLR)
			v->m = DIS_CLR;
		else
			v->m = CLR;
	}
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
		yz_asgn(v);
}

void	controls_two(t_mlx *v, int keycode)
{
	if (keycode == 123)
		v->padx -= 70.;
	else if (keycode == 78 && (v->z > 10 || v->z < -10))
	{
		v->z -= (v->z * 0.30);
		v->imax -= 2.;
	}
	else if (keycode == 124)
		v->padx += 70.;
	else if (keycode == 126)
		v->pady -= 70.;
	else if (keycode == 125)
		v->pady += 70.;
}
