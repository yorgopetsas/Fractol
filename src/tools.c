/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorgopetsas <yorgopetsas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/12 17:29:52 by yorgopetsas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// My Put Pixel Function
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	yz_key_hook(int keycode, t_mlx *mx)
{
	t_mlx	*y;

	y = mx;
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		printf("OOOPS, somebody pressed 'ESC'.\nThe Window is Closing.\n");
		// mlx_destroy_image(mx->mlx, mx->win);
		// mlx_destroy_window(mx->mlx, mx->win);
		exit (0);
	}
	return (0);
}

int	yz_mouse_hook(int keycode, t_mlx *mx)
{
	t_mlx	*y;

	y = mx;
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		printf("OOOPS, somebody pressed 'ESC'.\nThe Window is Closing.\n");
		exit (0);
	}
	return (0);
}
