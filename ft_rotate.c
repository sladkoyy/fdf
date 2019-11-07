/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:10:35 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 18:30:43 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_rotate_z(int *x, int *y, t_angle *angles)
{
	int		previous_x;
	int		previous_y;
	int		x_dot;
	int		y_dot;

	previous_x = *x;
	previous_y = *y;
	x_dot = ((*angles).lenj * (*angles).t) / 2;
	y_dot = ((*angles).leni * (*angles).t) / 2;
	*x = (previous_x - x_dot) *
	cos(1 / 57.2958 * (*angles).angle) - (previous_y - y_dot) *
	sin(1 / 57.2958 * (*angles).angle);
	*y = (previous_x - x_dot) *
	sin(1 / 57.2958 * (*angles).angle) + (previous_y - y_dot) *
	cos(1 / 57.2958 * (*angles).angle);
}

static void		ft_rotate_x(int *y, int *z, t_angle *angles)
{
	int		previous_y;
	int		previous_z;

	previous_y = *y;
	previous_z = *z * ((*angles).t * (*angles).alt) / 45;
	*y = previous_y *
	cos(1 / 57.2958 * (*angles).anglex) + previous_z *
	sin(1 / 57.2958 * (*angles).anglex);
	*z = -1 * previous_y *
	sin(1 / 57.2958 * (*angles).anglex) + previous_z *
	cos(1 / 57.2958 * (*angles).anglex);
}

static void		ft_rotate_y(int *x, int *z, t_angle *angles)
{
	int		previous_x;
	int		previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = previous_x *
	cos(1 / 57.2958 * (*angles).angley) + previous_z *
	sin(1 / 57.2958 * (*angles).angley);
	*z = -1 * previous_x *
	sin(1 / 57.2958 * (*angles).angley) + previous_z *
	cos(1 / 57.2958 * (*angles).angley);
}

void			ft_rotate(int *x, int *y, int z, t_angle *angles)
{
	int		tmp_z;

	tmp_z = z;
	ft_rotate_z(x, y, angles);
	ft_rotate_x(y, &tmp_z, angles);
	ft_rotate_y(x, &tmp_z, angles);
}
