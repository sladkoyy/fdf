/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:37:45 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/26 15:21:31 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

static char		*ft_strjoin_buf(char *s1, char *s2, int bytes)
{
	size_t		l;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + bytes;
	if (!(str = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_memmove(&str[ft_strlen(s1)], s2, bytes);
	str[l] = '\0';
	if (s1[0] != '\0')
		ft_strdel(&s1);
	return (str);
}

static int		ft_checknewline(char *tmp)
{
	int			i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char		*ft_result(char **tmp, int fd)
{
	char		*res;
	char		*end;
	int			len;
	int			i;

	len = ft_strlen(tmp[fd]);
	i = ft_checknewline(tmp[fd]);
	if (i == -1)
	{
		res = ft_strdup(tmp[fd]);
		ft_strdel(&tmp[fd]);
	}
	else
	{
		res = ft_strsub(tmp[fd], 0, i);
		end = ft_strsub(tmp[fd], i + 1, len
		- ft_strlen(res) - 1);
		ft_strdel(&tmp[fd]);
		tmp[fd] = ft_strsub(end, 0, ft_strlen(end));
		ft_strdel(&end);
	}
	return (res);
}

int				get_next_line(int fd, char **line)
{
	static char	*tmp[MYFD];
	char		buf[BUFF_SIZE];
	int			bytes;

	if (fd < 0 || fd > MYFD || line == NULL)
		return (-1);
	if (tmp[fd] == NULL)
		tmp[fd] = "";
	while (ft_checknewline(tmp[fd]) < 0)
	{
		if ((bytes = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (bytes == 0)
			break ;
		tmp[fd] = ft_strjoin_buf(tmp[fd], buf, bytes);
	}
	if (bytes == 0 && *tmp[fd] == '\0')
		return (0);
	else
	{
		*line = ft_result(tmp, fd);
		return (1);
	}
}
