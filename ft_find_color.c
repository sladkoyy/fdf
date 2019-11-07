/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:03:30 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 18:30:18 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_base(char *str, int *base)
{
	int		i;

	*base = 10;
	i = 0;
	if (str[i])
	{
		if (str[i] == '0')
		{
			i++;
			if (ft_toupper(str[i]) == 'X')
			{
				*base = 16;
				i++;
			}
			else if (ft_toupper(str[i]) == 'B')
			{
				*base = 2;
				i++;
			}
			else
				*base = 8;
		}
	}
	return (i);
}

static int		ft_take_color(char *str, int ind)
{
	int		base;
	int		digit;
	int		res;
	int		i;

	i = ft_base(str, &base);
	res = 0;
	digit = 0;
	while (i <= ind)
	{
		digit = ft_toupper(str[i++]);
		digit = (digit >= 'A') ? digit - 'A' + 0x0a : digit - '0';
		if (digit >= 0 && digit < base)
			res = res * base + digit;
		else
			return (0);
	}
	return (res);
}

int				ft_find_color(char *str)
{
	int		color;

	color = ft_take_color(str, ft_strlenc(str, ' ') - 1);
	return (color);
}
