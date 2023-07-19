/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/20 01:22:28 by yzisis-p         ###   ########.fr       */
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
	v->len = WW - 50 - ft_strlen(v->nam) * 10;

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
	mlx_string_put(v->mlx, v->win, 41, 35, CLR, "Controls Keys");
	mlx_string_put(v->mlx, v->win, 1037, 63, CLR, "Move = ^ v < >");
	mlx_string_put(v->mlx, v->win, 1037, 83, CLR, "Iter = W and Q");
	mlx_string_put(v->mlx, v->win, 1037, 103, CLR, "Zoom = - and +");
	mlx_string_put(v->mlx, v->win, 1037, 123, CLR, "Rot8 = R and T");
	mlx_string_put(v->mlx, v->win, 1037, 143, CLR, "Mouse = M or S");
	mlx_string_put(v->mlx, v->win, 1037, 163, CLR, "Color = SHIFT");
	mlx_string_put(v->mlx, v->win, 1037, 183, CLR, "Reset = CLEAR");
	mlx_string_put(v->mlx, v->win, 37, 248, v->m, "Controls Mouse");
	mlx_string_put(v->mlx, v->win, 37, 276, v->m, "Zoom = SCROLL");
	mlx_string_put(v->mlx, v->win, 37, 296, v->m, "or LMB and RMB");
	mlx_string_put(v->mlx, v->win, 37, (HH - 123), CLR, "Fract Explorer");
	mlx_string_put(v->mlx, v->win, 37, (HH - 95), CLR, "1 = Julia");
	mlx_string_put(v->mlx, v->win, 37, (HH - 75), CLR, "2 = Mandelbrot");
	mlx_string_put(v->mlx, v->win, 37, (HH - 55), CLR, "3 = Tricorn");
	mlx_string_put(v->mlx, v->win, v->len + 11, (HH - 55), CLR, v->nam);
	// free(v->nam);
}

// void	yz_mlx_draw(t_mlx *v, int x, int y, int clr)
// {
// 	int	tmp1;
// 	int	tmp2;

// 	tmp1 = x;
// 	tmp2 = y;
// 	v->clr = ft_shade_color(clr, 0.20);

// 	// while (v->x <= x && mlx_pixel_put(v->mlx, v->win, v->x, v->y, v->clr) == 0)
// 	// 	v->x++;
// 	// while (v->y <= y && mlx_pixel_put(v->mlx, v->win, v->x, v->y, v->clr) == 0)
// 	// 	v->y++;
// 	// while (v->x > tmp1 && mlx_pixel_put(v->mlx, v->win, v->x, v->y, v->clr) == 0)
// 	// 	v->x--;
// 	while (v->y > tmp2 && mlx_pixel_put(v->mlx, v->win, v->x, v->y, v->clr) == 0)
// 		v->y--;
// }

// void	iface(t_mlx *v)
// {
// 	v->x = 25;
// 	v->y = 25;
// 	// yz_mlx_draw(v, 188, 213, CLR);
// 	v->y = 237;
// 	// yz_mlx_draw(v, 188, 326, v->m);
// 	v->y = HH - 133;
// 	yz_mlx_draw(v, 188, (HH - 25), CLR);
// 	v->y = (HH - 65);
// 	v->x = v->len - 1;
// 	yz_mlx_draw(v, (WW - 25), (HH - 25), CLR);
// }