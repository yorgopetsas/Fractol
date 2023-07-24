/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzisis-p <yzisis-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:14:58 by yzisis-p          #+#    #+#             */
/*   Updated: 2023/07/25 01:40:50 by yzisis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	yz_countdown(double result2, int *decd)
{
	while (decd > 0)
	{
		result2 /= 10.0;
		decd--;
	}
	return (result2);
}

double	yz_calc_result(char *argv, int *decd, int decs, int sign)
{
	double	result;

	if (sign == -1)
		argv++;
	while (*argv)
	{
		if (*argv >= '0' && *argv <= '9')
		{
			if (decs)
			{
				result = result * 10 + (*argv - '0');
				decd++;
			}
			else
				result = result * 10 + (*argv - '0');
		}
		else if (*argv == '.' || *argv == ',' )
			decs = 1;
		else
			break ;
		argv++;
	}
	result = yz_countdown(result, decd);
	return (result);
}

int	yz_check_sign(char *argv)
{
	int	sign;

	sign = 1;
	if (*argv == '-')
	{
		sign = -1;
		argv++;
	}
	else if (*argv == '+')
		argv++;
	return (sign);
}

double	yz_string_double(char *argv)
{
	double	result;
	int		sign;
	int		*decd;
	int		decs;


	result = 0.0;
	decd = 0;
	decs = 0;
	sign = 1;
	sign = yz_check_sign(argv);
	result = yz_calc_result(argv, decd, decs, sign);
	return (result * sign);
}
