/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoy <dtoy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:03:45 by dtoy              #+#    #+#             */
/*   Updated: 2019/04/29 18:04:37 by dtoy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_push_list(t_color **head, int i, int j, int color)
{
	t_color *tmp;

	tmp = (t_color*)ft_memalloc(sizeof(t_color));
	tmp->i = i;
	tmp->j = j;
	tmp->color = color;
	tmp->next = (*head);
	(*head) = tmp;
}
