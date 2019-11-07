/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:05:31 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 18:16:35 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES_H
# define COORDINATES_H

typedef struct		s_axis
{
	int				x0;
	int				y0;
	int				y1;
	int				x1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
}					t_axis;

#endif
