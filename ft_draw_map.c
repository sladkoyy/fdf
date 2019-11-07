/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:44:43 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 18:22:57 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_put_color_j(t_color *head, int i, int j)
{
	int		color;

	color = 0x60fa23;
	while (head)
	{
		if ((head->j == j + 1 || head->j == j) && head->i == i)
		{
			color = head->color;
			break ;
		}
		else
			head = head->next;
	}
	return (color);
}

static int		ft_put_color_i(t_color *head, int i, int j)
{
	int		color;

	color = 0x60fa23;
	while (head)
	{
		if ((head->i == i + 1 || head->i == i) && head->j == j)
		{
			color = head->color;
			break ;
		}
		else
			head = head->next;
	}
	return (color);
}

static void		ft_draw_j(int **map, t_params *fdf, t_axis *axis)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < fdf->angles->leni)
	{
		j = 0;
		while (j + 1 < fdf->angles->lenj)
		{
			(*axis).x0 = j * fdf->angles->t;
			(*axis).y0 = i * fdf->angles->t;
			(*axis).x1 = (j + 1) * fdf->angles->t;
			(*axis).y1 = i * fdf->angles->t;
			ft_rotate(&(*axis).x0, &(*axis).y0, map[i][j], fdf->angles);
			ft_rotate(&(*axis).x1, &(*axis).y1, map[i][j + 1], fdf->angles);
			ft_movedots(fdf, axis);
			color = ft_put_color_j(fdf->head, i, j);
			ft_draw_line(axis, fdf, color);
			j++;
		}
		i++;
	}
}

static void		ft_draw_i(int **map, t_params *fdf, t_axis *axis)
{
	int		i;
	int		j;
	int		color;

	j = 0;
	while (j < fdf->angles->lenj)
	{
		i = 0;
		while (i + 1 < fdf->angles->leni)
		{
			(*axis).x0 = j * fdf->angles->t;
			(*axis).y0 = i * fdf->angles->t;
			(*axis).x1 = j * fdf->angles->t;
			(*axis).y1 = (i + 1) * fdf->angles->t;
			ft_rotate(&(*axis).x0, &(*axis).y0, map[i][j], fdf->angles);
			ft_rotate(&(*axis).x1, &(*axis).y1, map[i + 1][j], fdf->angles);
			ft_movedots(fdf, axis);
			color = ft_put_color_i(fdf->head, i, j);
			ft_draw_line(axis, fdf, color);
			i++;
		}
		j++;
	}
}

void			ft_draw_map(int **map, t_params *fdf)
{
	t_axis*axis;

	axis = (t_axis*)malloc(sizeof(t_axis));
	ft_draw_j(map, fdf, axis);
	ft_draw_i(map, fdf, axis);
	free(axis);
}
