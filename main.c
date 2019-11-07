/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:48:43 by dtoy              #+#    #+#             */
/*   Updated: 2019/11/07 18:34:15 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_draw_again(t_params *fdf)
{
	mlx_clear_window((*fdf).mlx_ptr, (*fdf).win_ptr);
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr,
	50, 50, 0x08f4fc, "Move: WASD");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr,
	50, 75, 0x08f4fc, "Rotate: Arrows & {, }");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr,
	50, 100, 0x08f4fc, "Alt: Num + & -");
	mlx_string_put((*fdf).mlx_ptr, (*fdf).win_ptr,
	50, 125, 0x08f4fc, "Zoom: + & -");
	ft_draw_map((*fdf).arr, fdf);
	return (0);
}

static void		ft_params(t_params *fdf)
{
	fdf->angles = (t_angle*)ft_memalloc(sizeof(t_angle));
	fdf->angles->alt = 10;
	fdf->angles->t = 15;
	fdf->angles->angle = 0;
	fdf->angles->anglex = 0;
	fdf->angles->angley = 0;
}

static int		ft_init_fdf(t_params *fdf, char **av, int ac)
{
	if (ft_validation(av, ac) == 0)
		return (0);
	ft_params(fdf);
	(*fdf).startx = WIN_WIDTH / 2;
	(*fdf).starty = WIN_HEIGHT / 2;
	if (!((*fdf).arr = ft_readfile(av[1], fdf)))
	{
		ft_putendl("Invalid file.");
		return (0);
	}
	(*fdf).mlx_ptr = mlx_init();
	(*fdf).win_ptr = mlx_new_window((*fdf).mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "f");
	mlx_hook((*fdf).win_ptr, 2, 0, ft_key_press, fdf);\
	mlx_loop_hook((*fdf).mlx_ptr, ft_draw_again, fdf);
	mlx_loop((*fdf).mlx_ptr);
	return (1);
}

int				main(int ac, char **av)
{
	t_params	*fdf;

	fdf = (t_params*)ft_memalloc(sizeof(t_params));
	if (ft_init_fdf(fdf, av, ac) == 0)
	{
		free(fdf->angles);
		free(fdf);
	}
	return (0);
}
