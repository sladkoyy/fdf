/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:41:33 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 18:17:08 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_it(t_axis *axis, t_params *fdf, int color)
{
	int		x;
	int		y;
	int		error;
	int		error2;

	x = (axis->x0);
	y = (axis->y0);
	error = (*axis).dx - (*axis).dy;
	while (x != (axis->x1) || y != (axis->y1))
	{
		mlx_pixel_put((*fdf).mlx_ptr, (*fdf).win_ptr, x, y, color);
		error2 = error * 2;
		if (error2 > (*axis).dy * -1)
		{
			error -= (*axis).dy;
			x += (*axis).sx;
		}
		if (error2 < (*axis).dx)
		{
			error += (*axis).dx;
			y += (*axis).sy;
		}
	}
	mlx_pixel_put((*fdf).mlx_ptr, (*fdf).win_ptr, x, y, color);
}

void			ft_draw_line(t_axis *axis, t_params *fdf, int color)
{
	(*axis).dx = abs((*axis).x1 - (*axis).x0);
	(*axis).dy = abs((*axis).y1 - (*axis).y0);
	(*axis).sx = (*axis).x0 < (*axis).x1 ? 1 : -1;
	(*axis).sy = (*axis).y0 < (*axis).y1 ? 1 : -1;
	ft_draw_it(axis, fdf, color);
}
