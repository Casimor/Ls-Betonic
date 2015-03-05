/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lstdnc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 20:38:13 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 13:23:57 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lstdnc(t_dlist **list)
{
	t_dlist	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			free((*list)->content);
			free(*list);
			*list = tmp;
		}
		*list = NULL;
	}
}
