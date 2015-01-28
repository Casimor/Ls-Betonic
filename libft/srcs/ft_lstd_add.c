/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 15:44:29 by ochase            #+#    #+#             */
/*   Updated: 2014/01/03 15:44:33 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_add(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	if (alst)
	{
		if (*alst)
		{
			tmp = *alst;
			while (tmp->next != *alst)
				tmp = tmp->next;
			new->next = *alst;
			new->previous = tmp;
			tmp->next = new;
			(*alst)->previous = new;
		}
		else
		{
			new->next = new;
			new->previous = new;
		}
		*alst = new;
	}
}
