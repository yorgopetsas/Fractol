/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/19 23:25:11 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	yz_error(int type)
{
	char	*str;

	if (type == 0)
		write(2, MSG0, ft_strlen(MSG0));
	else if (type == 1)
		write(2, MSG1, ft_strlen(MSG1));
	else if (type == 2)
	{
		str = "error : \n";
		write(2, str, ft_strlen(str));
		write(2, "\n", 2);
		write(2, MSG0, ft_strlen(MSG0));
		free(str);
	}
	write(2, "\n", 1);
	return (-1);
}

int	yz_check(t_mlx *v, char **av)
{
	ft_cpy("Julia\0", v->ftl[0]);
	ft_cpy("Mandelbrot\0", v->ftl[1]);
	if (ft_strcmp(av[1], "Julia") == 0)
		v->num = 1;
	else if (ft_strcmp(av[1], "Mandelbrot") == 0)
		v->num = 2;
	else
		return (1);
	return (0);
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
