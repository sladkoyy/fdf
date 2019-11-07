/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:02:53 by dtoy              #+#    #+#             */
/*   Updated: 2019/11/07 18:31:09 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_validation(char **av, int ac)
{
	(void)av;
	if (ac < 2)
	{
		ft_putendl("Too few arguments.");
		return (0);
	}
	if (ac > 2)
	{
		ft_putendl("Too many arguments.");
		return (0);
	}
	return (1);
}
