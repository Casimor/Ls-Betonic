/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 18:33:59 by ochase            #+#    #+#             */
/*   Updated: 2014/01/08 04:42:54 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstd_count(t_dlist *dlist, void *data)
{
	size_t	*c;

	(void)*dlist;
	c = (size_t *)data;
	++(*c);
}

size_t		ft_lstd_size(t_dlist *dlist)
{
	size_t	c;

	c = 0;
	ft_lstd_foreach(dlist, ft_lstd_count, &c);
	return (c);
}
