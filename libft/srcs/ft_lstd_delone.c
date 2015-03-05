/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 21:12:18 by ochase            #+#    #+#             */
/*   Updated: 2014/01/06 21:53:45 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_delone(t_dlist *alst, t_dlist **head)
{
	t_dlist	*tmp_previous;
	t_dlist	*tmp_next;

	tmp_previous = alst->previous;
	tmp_next = alst->next;
	if (alst == *head)
		*head = (alst == tmp_next ? 0 : tmp_next);
	free(alst->content);
	free(alst);
	tmp_previous->next = tmp_next;
	tmp_next->previous = tmp_previous;
}
