/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:52 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/25 17:41:23 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	yz_error(int type)
{
	if (type == 0)
	{
		write(2, INST, ft_strlen(INST));
		write(2, INST3, ft_strlen(INST3));
	}
	else if (type == 2)
	{
		write(2, INST2, ft_strlen(INST2));
		write(2, INST, ft_strlen(INST));
	}
	else if (type == 3)
	{
		write(2, INST4, ft_strlen(INST4));
		write(2, INST, ft_strlen(INST));
		write(2, INST3, ft_strlen(INST3));
	}
	else if (type == 5)
	{
		write(2, INST5, ft_strlen(INST4));
		write(2, INST3, ft_strlen(INST3));
		return (5);
	}
	write(2, "\n", 1);
	return (-1);
}

int	yz_check(t_mlx *v, char **argv, int argc)
{
	if (ft_strcmp(argv[1], "Julia") == 0)
	{
		if (argc == 3)
		{
			v->njr = yz_string_double(argv[2]);
			if (v->njr == 5)
				return (5);
		}
		v->num = 1;
	}
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		if (argc == 3)
			return (1);
		v->num = 2;
	}
	else if (ft_strcmp(argv[1], "Tricorn") == 0)
	{
		if (argc == 3)
			return (1);
		v->num = 3;
	}
	else
		return (1);
	return (0);
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
