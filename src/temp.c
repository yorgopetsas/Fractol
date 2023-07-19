/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/19 13:57:10 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

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

int				ft_hsv_to_hex(double h, double s, double v)
{
	t_hsv		hsv;
	t_rgb		rgb;

	hsv = (t_hsv){.h = h, .s = s, .v = v};
	rgb = ft_hsv_to_rgb(hsv);
	return (ft_rgb_to_hex(rgb));
}

int		ft_shade_color(int clr, double val)
{
	int r;
	int g;
	int b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor(D((clr >> 16) & 0xFF) - D(D((clr >> 16) & 0xFF) * val));
	g = floor(D((clr >> 8) & 0xFF) - D(D((clr >> 8) & 0xFF) * val));
	b = floor(D((clr) & 0xFF) - D(D((clr) & 0xFF) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	ft_rand(int min, int max)
{
	int i;
	int cpy;
	int num;
	int	res;

	i = 0;
	res = 0;
	num = (long)malloc(sizeof(long));
	if (num < 0)
		num = -num;
	cpy = num;
	while (num >= 10)
	{
		res += (num % 10);
		num = num / 10;
		i++;
	}
	res = res * 17 + cpy + i;
	res = (res % (max - min + 1)) + min;
	return (res);
}

t_hsv	ft_random_color(void)
{
	t_hsv	hsv;

	hsv.h = ((double)ft_rand(0, 3600) / 10.0);
	hsv.s = ((double)ft_rand(740, 810) / 1000.0);
	hsv.v = ((double)ft_rand(800, 950) / 1000.0);
	return (hsv);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	ft_cpy(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s1[++i] != 0)
		s2[i] = s1[i];
	s2[i] = 0;
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}



// t_hsv		ft_random_color(void)
// {
// 	t_hsv	hsv;

// 	hsv.h = ((double)ft_rand(0, 3600) / 10.0);
// 	hsv.s = ((double)ft_rand(740, 810) / 1000.0);
// 	hsv.v = ((double)ft_rand(800, 950) / 1000.0);
// 	return (hsv);
// }