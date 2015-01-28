/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lstd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 19:17:02 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 13:23:53 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lstd(t_dlist **list)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	if (list)
	{
		tmp = *list;
		while (tmp->next && tmp->next != *list)
		{
			tmp2 = tmp->next;
			free(tmp->content);
			free(tmp);
			tmp = tmp2;
		}
		free(tmp->content);
		free(tmp);
		*list = NULL;
	}
}
