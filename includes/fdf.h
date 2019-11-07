/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:05:23 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 19:48:45 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "coordinates.h"

# define WIN_WIDTH 1500
# define WIN_HEIGHT 1000

typedef struct	s_color
{
	int			color;
	int			i;
	int			j;
	void		*next;
}				t_color;

typedef struct	s_angle
{
	int			angle;
	int			anglex;
	int			angley;
	int			t;
	int			alt;
	int			leni;
	int			lenj;
}				t_angle;

typedef struct	s_params
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			startx;
	int			starty;
	int			tmp;
	int			**arr;
	t_color		*head;
	t_angle		*angles;
}				t_params;

void			ft_movedots(t_params *fdf, t_axis *axis);
void			ft_push_list(t_color **head, int i, int j, int color);
int				**ft_readfile(char *av, t_params *fdf);
void			ft_draw_line(t_axis *axis, t_params *fdf, int color);
int				ft_key_press(int x, t_params *fdf);
void			ft_rotate(int *x, int *y, int z, t_angle *angles);
void			ft_draw_map(int **map, t_params *fdf);
int				ft_validation(char **av, int ac);
int				ft_find_color(char *str);
int				**ft_clear_arr(int **res, t_params *fdf);
void			ft_clear_struct(t_color **head);

#endif
