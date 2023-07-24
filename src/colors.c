/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/24 17:20:12 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_rgb	ft_hsv_to_rgb(t_hsv hsv)
{
	t_rgb		rgb;
	double		p;
	double		q;
	double		t;

	(hsv.h == 360.) ? (hsv.h = 0.) : (hsv.h /= 60.);
	p = hsv.v * (1. - hsv.s);
	q = hsv.v * (1. - (hsv.s * (hsv.h - floor(hsv.h))));
	t = hsv.v * (1. - (hsv.s * (1. - (hsv.h - floor(hsv.h)))));
	rgb = (t_rgb){.r = 0., .g = 0., .b = 0.};
	if (hsv.s == 0.)
		rgb = (t_rgb){.r = hsv.v, .g = hsv.v, .b = hsv.v};
	else if (0. <= hsv.h && hsv.h < 1.)
		rgb = (t_rgb){.r = hsv.v, .g = t, .b = p};
	else if (1. <= hsv.h && hsv.h < 2.)
		rgb = (t_rgb){.r = q, .g = hsv.v, .b = p};
	else if (2. <= hsv.h && hsv.h < 3.)
		rgb = (t_rgb){.r = p, .g = hsv.v, .b = t};
	else if (3. <= hsv.h && hsv.h < 4.)
		rgb = (t_rgb){.r = p, .g = q, .b = hsv.v};
	else if (4. <= hsv.h && hsv.h < 5.)
		rgb = (t_rgb){.r = t, .g = p, .b = hsv.v};
	else if (5. <= hsv.h && hsv.h < 6.)
		rgb = (t_rgb){.r = hsv.v, .g = p, .b = q};
	return (rgb);
}

int	ft_rgb_to_hex(t_rgb rgb)
{
	int			r;
	int			g;
	int			b;

	r = (int)(rgb.r * 255.0);
	g = (int)(rgb.g * 255.0);
	b = (int)(rgb.b * 255.0);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	ft_hsv_to_hex(double h, double s, double v)
{
	t_hsv		hsv;
	t_rgb		rgb;

	hsv = (t_hsv){.h = h, .s = s, .v = v};
	rgb = ft_hsv_to_rgb(hsv);
	return (ft_rgb_to_hex(rgb));
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