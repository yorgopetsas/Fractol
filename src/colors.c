/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/25 15:10:47 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	yz_rgb_2(t_rgb clrz)
{
	int	r;
	int	g;
	int	b;

	r = (int)(255 * (clrz.red + clrz.m));
	g = (int)(255 * (clrz.green + clrz.m));
	b = (int)(255 * (clrz.blue + clrz.m));
	return ((r << 16) | (g << 8) | b);
}

void	yz_rgb_range(t_rgb *clrz, double r, double g, double b)
{
	clrz->red = r;
	clrz->green = g;
	clrz->blue = b;
}

int	yz_rgb_init(t_rgb clrz)
{
	int	result;

	if (clrz.hue >= 0.0 && clrz.hue < 120.0)
		yz_rgb_range(&clrz, clrz.c, clrz.c, 0.0);
	else if (clrz.hue >= 60.0 && clrz.hue < 90.0)
		yz_rgb_range(&clrz, clrz.x, clrz.c, 0.0);
	else if (clrz.hue >= 90.0 && clrz.hue < 120.0)
		yz_rgb_range(&clrz, (clrz.x * 1.1), (clrz.c * 1.1), 0.0);
	else if (clrz.hue >= 120.0 && clrz.hue < 180.0)
		yz_rgb_range(&clrz, 0.0, clrz.c, clrz.x);
	else if (clrz.hue >= 180.0 && clrz.hue < 240.0)
		yz_rgb_range(&clrz, 0.0, (clrz.c * 0.9), (clrz.x * 0.9));
	else if (clrz.hue >= 180.0 && clrz.hue < 240.0)
		yz_rgb_range(&clrz, 0.0, clrz.x, clrz.c);
	else if (clrz.hue >= 240.0 && clrz.hue < 300.0)
		yz_rgb_range(&clrz, clrz.x, 0.0, clrz.c);
	else
		yz_rgb_range(&clrz, clrz.c, 0.0, clrz.x);
	result = yz_rgb_2(clrz);
	return (result);
}

int	yz_coloring(t_mlx *v)
{
	t_rgb	clrz;
	int		r;

	if (v->i >= v->imax)
		return (0x000000);
	clrz.hue = v->clr_h + (v->i * (360.0 / v->imax));
	while (clrz.hue < 0.0)
		clrz.hue += 360.0;
	while (clrz.hue >= 360.0)
		clrz.hue -= 360.0;
	clrz.saturation = 0.8;
	clrz.value = 1.0;
	clrz.c = clrz.value * clrz.saturation;
	clrz.x = clrz.c * (1.0 - fabs(fmod(clrz.hue / 60.0, 2.0) - 1.0));
	clrz.m = clrz.value - clrz.c;
	r = yz_rgb_init(clrz);
	return (r);
}
