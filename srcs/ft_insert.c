/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:29:25 by ochase            #+#    #+#             */
/*   Updated: 2013/12/02 18:45:46 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"

void	ft_lstsort(t_list **list, const t_info *info, t_cmp cmp, int rev)
{
	t_list	*new_elem;
	t_list	*it;

	new_elem = ft_lstnew(info, sizeof(t_info));
	if (!*list || (cmp(info, (t_info *)((*list)->content), rev) < 0))
	{
		ft_lstadd(list, new_elem);
		return ;
	}
	it = *list;
	while (it->next)
	{
		if (cmp(info, (t_info *)it->next->content, rev) < 0)
		{
			new_elem->next = it->next;
			it->next = new_elem;
			return ;
		}
		it = it->next;
	}
	it->next = new_elem;
}
