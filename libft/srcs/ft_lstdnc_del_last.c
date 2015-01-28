/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnc_del_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 02:39:32 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 13:26:28 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdnc_del_last(t_dlist **list)
{
	t_dlist	*it;
	t_dlist	*tmp;

	if (list)
	{
		it = *list;
		while (it->next)
			it = it->next;
		if (it->previous)
		{
			tmp = it->previous;
			tmp->next = NULL;
			free(it);
		}
		else
		{
			free(*list);
			*list = NULL;
		}
		free(it->content);
	}
}
