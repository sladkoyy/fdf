/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:34:49 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 19:47:17 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**ft_clear_arr(int **res, t_params *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->angles->leni)
	{
		free(res[i]);
		i++;
	}
	free(res);
	res = NULL;
	return (res);
}
