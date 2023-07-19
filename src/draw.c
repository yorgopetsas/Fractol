/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/19 18:06:55 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		put_pixel(t_mlx *v, int type)
{
	int		i;
	int		x;
	int		y;
	char	*rgb;

	x = v->x;
	y = v->y;

	i = type;
	rgb = "hola";
	if (((type == 1 && x > 213) || (type != 1 && x >= 0))
			&& x < WW && y >= 0 && y < HH)
	{
		i = ((int)v->x * (v->bits_per_pixel / 8)) + ((int)v->y * v->sl);
		rgb = (char*)&v->clr;
		v->d[i] = rgb[0];
		v->d[++i] = rgb[1];
		v->d[++i] = rgb[2];
	}
	return (0);
}

void	draw_fractal(t_mlx *v)
{
	v->y = -1;
	v->nam = "Fractal : ";
	v->len = WW - 50 - ft_strlen(v->nam) * 10;

	// fractal_mandelbrot(v);
	rotate_fractal(v, v->rot);
	while (++v->y < HH && (v->x = -1) == -1)
	{
		while (++v->x < WW)
		{
			if (v->num == 1)
				fractal_julia(v);
			else if (v->num == 2)
				// yz_print_mandelbrat(v);
				// fractal_julia(v);
				fractal_mandelbrot(v);
			else if (v->num == 3)
				fractal_mandelbrot(v);
		}
	}
}

void	yz_mlx_draw(t_mlx *v, int x, int y, int clr)
{
	int tmp1;
	int tmp2;

	tmp1 = x;
	tmp2 = y;
	v->clr = ft_shade_color(clr, 0.20);

	// mlx_string_put(v.mlx, v.win, 100, 100, 0x00888020, (char)v.clr);
	// mlx_string_put(v.mlx, v.win, 200, 100, 0x00888020, (char)v.x);
	// mlx_string_put(v.mlx, v.win, 300, 100, 0x00888020, (char)v.y);

	// while (v->x <= x && put_pixel(v, 0) == 0)
	// 	v->x++;
	// while (v->y <= y && put_pixel(v, 0) == 0)
	// 	v->y++;
	// while (v->x > tmp1 && put_pixel(v, 0) == 0)
	// 	v->x--;
	// while (v->y > tmp2 && put_pixel(v, 0) == 0)
	// 	v->y--;
}

// void	yz_mlx_draw(t_mlx *v, int x, int y, int clr)
// {
// 	int	tmp1;
// 	int	tmp2;

// 	tmp1 = v->x;
// 	tmp2 = v->y;
// 	v->clr = ft_shade_color(clr, 0.20);
// 	while (v->x <= x && mlx_pixel_put(v->mlx, v->win, x, y, 0x00888020) == 0)
// 		v->x++;
// 	while (v->y <= y && mlx_pixel_put(v->mlx, v->win, x, y, 0x00888020) == 0)
// 		v->y++;
// 	while (v->x > tmp1 && mlx_pixel_put(v->mlx, v->win, x, y, 0x00888020) == 0)
// 		v->x--;
// 	while (v->y > tmp2 && mlx_pixel_put(v->mlx, v->win, x, y, 0x00888020) == 0)
// 		v->y--;
// }

void	user_interface(t_mlx *v)
{
	// mlx_string_put(v->mlx, v->win, 100, 100, 0x00888020, "NAME");
	// mlx_pixel_put(v->mlx, v->win, 20, 20, 0x00888020);
	// mlx_pixel_put(v->mlx, v->win, 21, 20, 0x00888020);
	// mlx_pixel_put(v->mlx, v->win, 22, 20, 0x00888020);
	// mlx_pixel_put(v->mlx, v->win, 23, 20, 0x00888020);
	v->x = 25;
	v->y = 25;
	yz_mlx_draw(v, 188, 213, UI_CLR);
	v->y = 237;
	yz_mlx_draw(v, 188, 326, v->m);
	v->y = HH - 133;
	yz_mlx_draw(v, 188, (HH - 25), UI_CLR);
	v->y = (HH - 65);
	v->x = v->len - 1;
	yz_mlx_draw(v, (WW - 25), (HH - 25), UI_CLR);
}

void	user_interface_texts(t_mlx *v)
{
	mlx_string_put(v->mlx, v->win, 41, 35, UI_CLR, "Controls Keys");
	mlx_string_put(v->mlx, v->win, 37, 63, UI_CLR, "Move = ^ v < >");
	mlx_string_put(v->mlx, v->win, 37, 83, UI_CLR, "Iter = W and Q");
	mlx_string_put(v->mlx, v->win, 37, 103, UI_CLR, "Zoom = - and +");
	mlx_string_put(v->mlx, v->win, 37, 123, UI_CLR, "Rot8 = R and T");
	mlx_string_put(v->mlx, v->win, 37, 143, UI_CLR, "Mouse = M or S");
	mlx_string_put(v->mlx, v->win, 37, 163, UI_CLR, "Color = SHIFT");
	mlx_string_put(v->mlx, v->win, 37, 183, UI_CLR, "Reset = CLEAR");
	mlx_string_put(v->mlx, v->win, 37, 248, v->m, "Controls Mouse");
	mlx_string_put(v->mlx, v->win, 37, 276, v->m, "Zoom = SCROLL");
	mlx_string_put(v->mlx, v->win, 37, 296, v->m, "or LMB and RMB");
	mlx_string_put(v->mlx, v->win, 37, (HH - 123), UI_CLR, "Fract Explorer");
	mlx_string_put(v->mlx, v->win, 37, (HH - 95), UI_CLR, "1 = Julia");
	mlx_string_put(v->mlx, v->win, 37, (HH - 75), UI_CLR, "2 = Mandelbrot");
	mlx_string_put(v->mlx, v->win, 37, (HH - 55), UI_CLR, "3 = Tricorn");
	mlx_string_put(v->mlx, v->win, v->len + 11, (HH - 55), UI_CLR, v->nam);
	// free(v->nam);
}
