/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:09:02 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/20 01:18:48 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	rotate_fractal(t_mlx *v, int rot)
{
	if (rot >= 0)
		while (rot >= 360)
			rot -= 360;
	else
		while (rot < -0)
			rot += 360;
	if (rot == 0 && (v->e = 0) == 0)
		while (v->z < 0)
			v->z = v->z * -1;
	else if (rot == 90 && (v->e = 1) == 1)
		while (v->z < 0)
			v->z = v->z * -1;
	else if (rot == 180 && (v->e = 2) == 2)
		while (v->z > 0)
			v->z = v->z * -1;
	else if (rot == 270 && (v->e = 3) == 3)
		while (v->z > 0)
			v->z = v->z * -1;
	v->minx = ((MW + v->padx) / (v->z / 2)) / -2;
	v->miny = ((MH + v->pady) / (v->z / 2)) / -2;
}

int	edit_hue_hex(t_mlx *v)
{
	t_hsv	hsv;
	t_rgb	rgb;

	if (v->i == v->imax)
		return (0x000000);
	else
	{
		hsv.h = v->clr_h + ((240. / v->imax) * v->i);
		hsv.s = v->clr_s;
		hsv.v = v->clr_v - (((v->clr_v - 0.10) / 100.0) * v->i);
		while (hsv.h < 0.)
			hsv.h += 360.0;
		while (hsv.h > 360.)
			hsv.h -= 360.0;
		rgb = ft_hsv_to_rgb(hsv);
	}
	return (ft_rgb_to_hex(rgb));
}

void	fractal_julia(t_mlx *v)
{
	v->i = -1.0;
	v->mod = 2;

	if (v->e == 0 || v->e == 2) 
		v->zr = ((double)(v->x) / v->z) + v->minx;
	else
		v->zr = ((double)(v->y) / v->z) + v->miny;
	if (v->e == 0 || v->e == 2) 
		v->zi = ((double)(v->y) / v->z) + v->miny;
	else
		v->zi = ((double)(v->x) / v->z) + v->minx;
	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->jr;
		v->zi = v->mod * v->zi * v->tmp + v->ji;
	}
	v->clr = edit_hue_hex(v);
	mlx_pixel_put(v->mlx, v->win, v->x, v->y, v->clr);
}

void	fractal_mandelbrot(t_mlx *v)
{
	v->i = -2.0;
	v->zr = 0.0;
	v->zi = 0.0;

	if (v->num == 2) 
		v->mod = 2;
	else
		v->mod = -2;
	if (v->e == 0 || v->e == 2) 
		v->mr = ((double)(v->x) / v->z) + v->minx;
	else
		v->mr = ((double)(v->y) / v->z) + v->miny;
	if (v->e == 0 || v->e == 2)
		v->mi = ((double)(v->y) / v->z) + v->miny;
	else
		v->mi = ((double)(v->x) / v->z) + v->minx;
	while (++v->i < v->imax && (v->zr * v->zr + v->zi * v->zi) < 4)
	{
		v->tmp = v->zr;
		v->zr = (v->zr * v->zr) - (v->zi * v->zi) + v->mr;
		v->zi = v->mod * v->zi * v->tmp + v->mi;
	}
	v->clr = edit_hue_hex(v);
	mlx_pixel_put(v->mlx, v->win, v->x, v->y, v->clr);
}
