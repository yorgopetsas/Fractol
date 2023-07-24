/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorgopetsas <yorgopetsas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/24 13:58:28 by yorgopetsas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	yz_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	yz_itr_frt(t_mlx *v)
{
	v->y = -1;
	v->nam = "Fractal : ";
	// v->len = WW - 50 - ft_strlen(v->nam) * 10;

	rotate_fractal(v, v->rot);
	while (++v->y < HH && (v->x = -1) == -1)
	{
		while (++v->x < WW)
		{
			if (v->num == 1)
				fractal_julia(v);
			else if (v->num == 2)
				fractal_mandelbrot(v);
		}
	}
}

void	yz_menu(t_mlx *v)
{
	char	*ttl;

	if (v->num == 1)
		ttl = "Fractal: Julia";
	else
		ttl = "Fractal: Mandelbrot";

	mlx_string_put(v->mlx, v->win, 1037, 35, CLR, "Controls");
	mlx_string_put(v->mlx, v->win, 1037, 63, CLR, "Move = ^ v < >");
	mlx_string_put(v->mlx, v->win, 1037, 83, CLR, "Iter = W and Q");
	mlx_string_put(v->mlx, v->win, 1037, 103, CLR, "Zoom = I or O");
	mlx_string_put(v->mlx, v->win, 1037, 123, CLR, "Rotate = R and T");
	mlx_string_put(v->mlx, v->win, 1037, 143, CLR, "Mouse = M or S");
	mlx_string_put(v->mlx, v->win, 1037, 163, CLR, "Color = SHIFT");
	mlx_string_put(v->mlx, v->win, 1037, 183, CLR, "Reset = C");
	mlx_string_put(v->mlx, v->win, 1037, 248, CLR, "Controls Mouse");
	mlx_string_put(v->mlx, v->win, 1037, 276, CLR, "Zoom = SCROLL");
	mlx_string_put(v->mlx, v->win, 1037, 296, CLR, "or LMB and RMB");
	mlx_string_put(v->mlx, v->win, 1037, (HH - 75), CLR, ttl);
	mlx_string_put(v->mlx, v->win, 1037, (HH - 75), CLR, ttl);
	// free(v->nam);
}
