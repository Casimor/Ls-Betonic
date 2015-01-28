/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:49:21 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 13:21:01 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_pushback(t_dlist **begin, t_dlist *new)
{
	t_dlist	*tmp;

	if (begin)
	{
		if (*begin)
		{
			tmp = *begin;
			while (tmp->next != *begin)
				tmp = tmp->next;
			tmp->next = new;
			(*begin)->previous = new;
			new->next = *begin;
			new->previous = tmp;
		}
		else
		{
			new->next = new;
			new->previous = new;
			*begin = new;
		}
	}
}
