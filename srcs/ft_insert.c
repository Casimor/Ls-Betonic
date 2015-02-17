/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:29:25 by ochase            #+#    #+#             */
/*   Updated: 2015/02/17 21:48:53 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_files(char *name, t_list **f_lst)
{
	t_list	*it;
	t_list	*new_elem;

	new_elem = ft_lstnew(name, ft_strlen(name) + 1);
	if (!*f_lst)
		ft_lstadd(f_lst, new_elem);
	else
	{
		it = *f_lst;
		while (it->next)
			it = it->next;
		it->next = new_elem;
	}
}

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

int		lstaddinfo(t_list **lst, const t_info *info, t_dirent *dir, t_opt *opt)
{
	t_list	*new_elem;
	t_list	*it;

	if (!info)
		return (perm_denied(lst, dir->d_name, opt));
	new_elem = ft_lstnew(info, sizeof(t_info));
	if (!*lst)
	{
		ft_lstadd(lst, new_elem);
		return (0);
	}
	else
	{
		it = *lst;
		while (it->next)
			it = it->next;
		it->next = new_elem;
		return (0);
	}
}
