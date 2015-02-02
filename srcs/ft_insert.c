/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:29:25 by ochase            #+#    #+#             */
/*   Updated: 2015/02/02 14:23:47 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lstsort(t_list **list, t_cmp cmp, int rev)
{
	t_list	*it;
	t_list	*tmp_c;
	t_list	*tmp;
	t_list	*tmp_n;

	it = *list;
	while (it)
	{
		tmp = it;
		tmp_n = it->next;
		while (tmp_n)
		{
			if (cmp((t_info *)tmp->content, (t_info *)tmp_n->content, rev) < 0)
			{
				tmp_c = tmp->content;
				tmp->content = tmp_n->content;
				tmp_n->content = tmp_c;
			}
			tmp_n = tmp_n->next;
		}
		it = it->next;
	}
}

void	lstaddinfo(t_list **list, const t_info *info)
{
	t_list	*new_elem;
	t_list	*it;

	new_elem = ft_lstnew(info, sizeof(t_info));
	if (!*list)
		ft_lstadd(list, new_elem);
	else
	{
		it = *list;
		while (it->next)
			it = it->next;
		it->next = new_elem;
	}
}
