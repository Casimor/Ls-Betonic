/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_maxsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 09:26:52 by ochase            #+#    #+#             */
/*   Updated: 2014/01/08 09:27:16 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_maxsize(t_dlist *dlist, void *data)
{
	size_t	*c;

	c = (size_t *)data;
	if (dlist->content_size > *c)
		*c = dlist->content_size;
}

size_t		ft_get_maxsize(t_dlist *dlist)
{
	size_t	c;

	c = 0;
	ft_lstd_foreach(dlist, ft_maxsize, &c);
	return (c);
}
