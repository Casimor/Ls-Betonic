/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:53:56 by ochase            #+#    #+#             */
/*   Updated: 2014/01/06 21:32:26 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_foreach(t_dlist *dlist, t_dlistf f, void *data)
{
	t_dlist	*tmp;

	if (dlist)
	{
		tmp = dlist;
		while (dlist->next != tmp)
		{
			f(dlist, data);
			dlist = dlist->next;
		}
		f(dlist, data);
	}
}
