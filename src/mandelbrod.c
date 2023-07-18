/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorgopetsas <yorgopetsas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:18:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/12 19:33:16 by yorgopetsas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Function to calculate the Mandelbrot fractal for a given pixel

void	yz_init_mandelbrot_struct(t_fractol *fm)
{
	fm->maxiterations = 60;
	fm->color = 256;
	fm->minre = -1.5;
	fm->maxre = 1.5;
	fm->minim = -1.0;
	fm->maxim = 0;
	fm->maxim = fm->minim + (fm->maxre - fm->minre) * HH / WW;
	fm->re_factor = (fm->maxre - fm->minre) / (WW - 1);
	fm->im_factor = (fm->maxim - fm->minim) / (HH - 1);
	fm->isinside = 1;
	fm->cr = 0.0;
	fm->ci = 0.0;
	fm->zr = 0.0;
	fm->zr2 = 0.0;
	fm->zi = 0.0;
	fm->zi2 = 0.0;
}

void	man_calc_one(t_fractol *fm, unsigned int x)
{
	fm->cr = fm->minre + x * fm->re_factor;
	fm->zr = fm->cr;
	fm->zi = fm->ci;
	fm->isinside = 1;
}

void	man_calc_two(t_fractol *fm, unsigned int n)
{
	while (n < fm->maxiterations)
	{
		fm->zr2 = fm->zr * fm->zr;
		fm->zi2 = fm->zi * fm->zi;
		if (fm->zr2 + fm->zi2 > 4)
		{
			fm->isinside = 0;
			break ;
		}
		fm->zi = 2 * fm->zr * fm->zi + fm->ci;
		fm->zr = fm->zr2 - fm->zi2 + fm->cr;
		n++;
	}
}

void	yz_mandel_calc(t_fractol *fm, t_mlx *mx)
{
	unsigned int	y;

	y = 0;
	while (y < HH)
	{
		fm->ci = fm->maxim - y * fm->im_factor;
		unsigned x = 0;
		while (x < WW)
		{
			man_calc_one(fm, x);
			unsigned n = 0;
			man_calc_two(fm, n);
			if (fm->isinside)
				my_mlx_pixel_put(mx, x, y, 0x00000000);
			else
				my_mlx_pixel_put(mx, x, y, 0x00547BE8);
			x++;
		}
		y++;
	}
}

void	yz_print_mandelbrat(t_mlx *mx)
{
	t_fractol	fm;

	yz_init_mandelbrot_struct(&fm);
	yz_mandel_calc(&fm, mx);
}
