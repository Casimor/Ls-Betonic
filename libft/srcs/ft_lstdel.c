/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 17:25:17 by ochase            #+#    #+#             */
/*   Updated: 2013/11/30 17:25:19 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*i;
	t_list	*tmp;

	if (alst)
	{
		i = *alst;
		while (i)
		{
			del(i->content, i->content_size);
			tmp = i->next;
			free(i);
			i = tmp;
		}
		*alst = NULL;
	}
}
