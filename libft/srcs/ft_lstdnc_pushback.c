/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnc_pushback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 20:26:27 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 13:25:02 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdnc_pushback(t_dlist **begin, t_dlist *new)
{
	t_dlist	*tmp;

	if (begin)
	{
		if (*begin)
		{
			tmp = *begin;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->next = NULL;
			new->previous = tmp;
		}
		else
		{
			new->next = NULL;
			new->previous = NULL;
			*begin = new;
		}
	}
}
