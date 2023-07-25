/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/25 03:02:52 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	yz_menu(t_mlx *v)
{
	char	*ttl;

	if (v->num == 1)
		ttl = "Fractal: Julia";
	else
		ttl = "Fractal: Mandelbrot";
	mlx_string_put(v->mlx, v->win, 1010, 5, 0x00FFFFFF, ttl);
	mlx_string_put(v->mlx, v->win, 1010, 5, CLR, ttl);
	mlx_string_put(v->mlx, v->win, 1010, 5, 0x00000000, ttl);
	mlx_string_put(v->mlx, v->win, 1010, 43, 0x00FFFFFF, "Actions:");
	mlx_string_put(v->mlx, v->win, 1010, 43, CLR, "Actions:");
	mlx_string_put(v->mlx, v->win, 1010, 43, 0x00000000, "Actions:");
	mlx_string_put(v->mlx, v->win, 1010, 63, CLR, "Move: Use Arrows");
	mlx_string_put(v->mlx, v->win, 1010, 83, CLR, "Incr/Decr Iterr: W / Q");
	mlx_string_put(v->mlx, v->win, 1010, 103, CLR, "Zoom = I or O");
	mlx_string_put(v->mlx, v->win, 1010, 123, CLR, "Rotate: R / T");
	mlx_string_put(v->mlx, v->win, 1010, 143, CLR, "Mouse On/Off: M / S");
	mlx_string_put(v->mlx, v->win, 1010, 163, CLR, "Change Colors: Shift");
	mlx_string_put(v->mlx, v->win, 1010, 183, CLR, "Reset = C");
	mlx_string_put(v->mlx, v->win, 1010, 203, CLR, "Mouse Controls:");
	mlx_string_put(v->mlx, v->win, 1010, 223, CLR, "Zoom: Scroll");
	mlx_string_put(v->mlx, v->win, 1010, 243, CLR, "Zoom: LMB / RMB");
}

void	yz_itr_frt(t_mlx *v)
{
	v->y = -1;
	yz_rotate_fractal(v, v->rot);
	while (++v->y < HH)
	{
		v->x = -1;
		while (++v->x < WW)
		{
			if (v->num == 1)
				fractal_julia(v);
			else if (v->num == 2)
				fractal_mandelbrot(v);
		}
	}
}
