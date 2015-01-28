/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:56:02 by ochase            #+#    #+#             */
/*   Updated: 2013/12/17 13:57:13 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list **list)
{
	t_list	*tmp;
	size_t	size;

	size = 0;
	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		++size;
	}
	return (size);
}
