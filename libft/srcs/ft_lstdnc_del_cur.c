/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnc_del_cur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 06:00:23 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 13:24:59 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdnc_del_cur(t_dlist **list)
{
	t_dlist		*tmp_previous;
	t_dlist		*tmp_next;

	tmp_previous = NULL;
	tmp_next = (*list)->next;
	if ((*list)->previous)
	{
		tmp_previous = (*list)->previous;
		tmp_previous->next = tmp_next;
	}
	free((*list)->content);
	free(*list);
	tmp_next->previous = tmp_previous;
}
