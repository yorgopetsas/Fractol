/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/26 14:57:43 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	yz_put_pixel(t_mlx *v, int type)
{
	int		i;
	int		x;
	int		y;
	char	*rgb;

	x = v->x;
	y = v->y;
	if ((type != 1 && x >= 0) && x < WW && y < HH)
	{
		i = ((int)v->x * (v->bpp / 8)) + ((int)v->y * v->sl);
		rgb = (char *)&v->clr;
		v->addr[i] = rgb[0];
		v->addr[++i] = rgb[1];
		v->addr[++i] = rgb[2];
	}
	return (0);
}

void	yz_menu(t_mlx *v)
{
	char	*ttl;

	if (v->num == 1)
		ttl = "Fractal: Julia";
	else if (v->num == 2)
		ttl = "Fractal: Mandelbrot";
	else
		ttl = "Fractal: Tricorn";
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
