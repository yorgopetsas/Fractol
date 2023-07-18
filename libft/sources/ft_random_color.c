/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 12:52:08 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/07 18:54:08 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hsv		ft_random_color(void)
{
	t_hsv	hsv;

	hsv.h = ((double)ft_rand(0, 3600) / 10.0);
	hsv.s = ((double)ft_rand(740, 810) / 1000.0);
	hsv.v = ((double)ft_rand(800, 950) / 1000.0);
	return (hsv);
}
