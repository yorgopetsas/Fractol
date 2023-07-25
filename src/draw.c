/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/25 13:26:58 by yzisis-p         ###   ########.fr       */
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
	mlx_string_put(v->mlx, v->win, 1010, 15, CLR, ttl);
	mlx_string_put(v->mlx, v->win, 1010, 15, CLR, ttl);
	mlx_string_put(v->mlx, v->win, 1010, 43, CLR, "Actions:");
	mlx_string_put(v->mlx, v->win, 1010, 43, CLR, "Actions:");
	mlx_string_put(v->mlx, v->win, 1010, 63, CLR, "Move: Use Arrows");
	mlx_string_put(v->mlx, v->win, 1010, 83, CLR, "Incr/Decr Iterr: W / Q");
	mlx_string_put(v->mlx, v->win, 1010, 103, CLR, "Zoom = I or O");
	mlx_string_put(v->mlx, v->win, 1010, 123, CLR, "Rotate: R / T");
	mlx_string_put(v->mlx, v->win, 1010, 143, CLR, "Reset = C");
	mlx_string_put(v->mlx, v->win, 1010, 163, CLR, "Mouse Controls:");
	mlx_string_put(v->mlx, v->win, 1010, 183, CLR, "Zoom: Scroll");
	mlx_string_put(v->mlx, v->win, 1010, 203, CLR, "Zoom: LMB / RMB");
	mlx_string_put(v->mlx, v->win, 1010, 223, CLR, "Change Colors: Shift");
	if (v->num == 1)
		mlx_string_put(v->mlx, v->win, 1010, 263, CLR, "Update JULIA: + / - ");

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
			if (v->x > 1000 && v->x < 1250 && v->y > 10 && v->y < 300)
				mlx_pixel_put(v->mlx, v->win, v->x, v->y, 0x00000000);
			else if (v->num == 1)
				fractal_julia(v);
			else if (v->num == 2)
				fractal_mandelbrot(v);
			else if (v->num == 3)
				fractal_mandelbrot(v);
		}
	}
}
