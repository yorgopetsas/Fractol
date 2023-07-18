/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorgopetsas <yorgopetsas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:18:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/12 19:32:42 by yorgopetsas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	yz_init_menu_str(t_menu *mu)
{
	mu->max_iterations = 60;
	mu->nx = 100;
	mu->ny = 100;
	mu->ax = 100;
	mu->ay = 120;
	mu->mx = 100;
	mu->my = 140;
	mu->color = 120;
	mu->max_iterations = 1;
}

void	yz_print_menu(t_mlx *mx)
{
	t_menu		mu;
	int			max_iterations;
	char		text;

	text = ' ';
	max_iterations = 1;
	yz_init_menu_str(&mu);
	mlx_string_put(mx->mlx, mx->win, mu.nx, mu.ny, mu.color, "NAME\\nN");
	// mlx_string_put(mx->mlx, mx->win, mu.ax, mu.ay, mu.color, "AUTHOR");
	// mlx_string_put(mx->mlx, mx->win, mu.mx, mu.my, mu.color, text);
}