/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by bsouchet          #+#    #+#             */
/*   Updated: 2023/07/24 19:36:16 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	edit_hue_hex(t_mlx *v)
{
	int	color_map[4];
	int color_index;
	int int_i;
	color_map[0] = 0x000000;
	color_map[1] = 0xFF0000;
	color_map[2] = 0x00FF00;
	color_map[3] = 0x0000FF;

	if (v->i >= v->imax)
	{
		return 0x000000;
	}
	int_i = (int)v->i;
	color_index = int_i % (sizeof(color_map) / sizeof(color_map[0]));
	return color_map[color_index];
}
