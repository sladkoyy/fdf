/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:16:47 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 18:23:58 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_arrows(int x, t_angle *angles)
{
	if (x == 123 || x == 65361)
		(*angles).angley -= 2;
	if (x == 124 || x == 65363)
		(*angles).angley += 2;
	if (x == 126 || x == 65362)
		(*angles).anglex -= 2;
	if (x == 125 || x == 65364)
		(*angles).anglex += 2;
	if (x == 33 || x == 91)
		(*angles).angle -= 2;
	if (x == 30 || x == 93)
		(*angles).angle += 2;
	if ((*angles).anglex == 360 || (*angles).anglex == -360)
		(*angles).anglex = 0;
	if ((*angles).angley == 360 || (*angles).angley == -360)
		(*angles).angley = 0;
	if ((*angles).angle == 360 || (*angles).angle == -360)
		(*angles).angle = 0;
}

static void		ft_wasd(int x, t_params *fdf)
{
	if (x == 0 || x == 97)
		(*fdf).startx -= 20;
	if (x == 2 || x == 100)
		(*fdf).startx += 20;
	if (x == 13 || x == 119)
		(*fdf).starty -= 20;
	if (x == 1 || x == 115)
		(*fdf).starty += 20;
}

static void		ft_zoom_and_alt(int x, t_angle *angles)
{
	if (x == 24 || x == 61)
	{
		if ((*angles).t < 150)
			(*angles).t += 1;
	}
	if (x == 27 || x == 45)
	{
		if ((*angles).t > 5)
			(*angles).t -= 1;
	}
	if (x == 78 || x == 65433)
	{
		if ((*angles).alt >= -25)
			(*angles).alt -= 1;
	}
	if (x == 69 || x == 65431)
	{
		if ((*angles).alt <= 25)
			(*angles).alt += 1;
	}
}

static void		ft_esc(int x, t_params *fdf)
{
	if (x == 53 || x == 65307)
	{
		mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		mlx_destroy_window((*fdf).mlx_ptr, (*fdf).win_ptr);
		if (fdf->head != NULL)
			ft_clear_struct(&fdf->head);
		if (fdf->arr != NULL)
			ft_clear_arr(fdf->arr, fdf);
		free(fdf->angles);
		free(fdf);
		exit(0);
	}
}

int				ft_key_press(int x, t_params *fdf)
{
	ft_arrows(x, fdf->angles);
	ft_wasd(x, fdf);
	ft_zoom_and_alt(x, fdf->angles);
	ft_esc(x, fdf);
	return (0);
}
