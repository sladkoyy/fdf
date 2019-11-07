/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:18:04 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 20:01:42 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_count_j(char *map, t_params *fdf)
{
	size_t		j;
	int			count;
	static int	t = 0;

	count = 0;
	j = 0;
	while (j < ft_strlen(map))
	{
		if (((ft_isdigit((int)map[j])) && j == 0) || map[j] == '-')
			count++;
		else if ((ft_isdigit((int)map[j])) && map[j - 1] == ' ')
			count++;
		j++;
	}
	if (fdf->tmp != count && t == 1)
		return (-1);
	fdf->tmp = count;
	if (t == 0)
		t = 1;
	return (count);
}

static int		ft_put_digit_in(int *res, char *map)
{
	int		j;
	int		a;

	j = 0;
	a = 0;
	if (map[j] == '0')
		res[a] = 0;
	else if (ft_isdigit((int)map[j]))
		res[a] = ft_atoi(&map[j]);
	else if (map[j] == '-')
		res[a] = ft_atoi(&map[j]);
	return (0);
}

static int		*ft_strtoint(t_params *fdf, char *map, int i)
{
	int		*res;
	size_t	j;
	int		a;
	int		color;

	a = 0;
	j = -1;
	res = (int*)ft_memalloc(sizeof(int) * fdf->angles->lenj);
	while (++j < ft_strlen(map))
	{
		if (map[j] == ',')
		{
			color = ft_find_color(&map[j + 1]);
			ft_push_list(&fdf->head, i, a - 1, color);
		}
		else if (((ft_isdigit((int)map[j])) && j == 0) || map[j] == '-' ||
		((ft_isdigit((int)map[j])) && map[j - 1] == ' '))
		{
			ft_put_digit_in(&res[a], &map[j]);
			a++;
		}
	}
	return (res);
}

static int		**ft_arrtoint(int count, char *av, t_params *fdf)
{
	int		**res;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fdf->angles->leni = count;
	res = (int**)ft_memalloc(sizeof(int*) * count);
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if ((fdf->angles->lenj = ft_count_j(line, fdf)) == -1)
		{
			res = ft_clear_arr(res, fdf);
			break ;
		}
		res[i] = ft_strtoint(fdf, line, i);
		ft_strdel(&line);
		i++;
	}
	if ((count >= 0 && fdf->angles->lenj == 0) ||
	(count == 1 && fdf->angles->lenj == 1))
		res = ft_clear_arr(res, fdf);
	close(fd);
	return (res);
}

int				**ft_readfile(char *av, t_params *fdf)
{
	int		fd;
	int		count;
	char	*line;
	int		**res;

	count = 0;
	res = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putendl("Invalid file.");
		return (res);
	}
	while (get_next_line(fd, &line))
	{
		count++;
		free(line);
	}
	if (count == 0)
	{
		ft_putendl("Invalid file.");
		return (res);
	}
	close(fd);
	res = ft_arrtoint(count, av, fdf);
	return (res);
}
