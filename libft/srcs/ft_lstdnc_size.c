/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnc_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 20:42:56 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 13:25:09 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstdnc_size(t_dlist *list)
{
	t_dlist	*tmp;
	size_t	c;

	c = 0;
	if (list)
	{
		tmp = list;
		while (tmp)
		{
			++c;
			tmp = tmp->next;
		}
	}
	return (c);
}
