/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:13:42 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/05 11:23:35 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_f(t_list *list)
{
	lstsort(&list, cmp_lexico, 1);
	return (list);
}

t_list		*ft_a(t_list *list)
{
	t_list		*tmp;
	t_list		*tmp_next;
	t_list		*tmp_previous;

	tmp = list;
	tmp_previous = NULL;
	while (tmp)
	{
		if (((t_info*)tmp->content)->name[0] == '.')
		{
			tmp_next = tmp->next;
			if (tmp_previous)
				tmp_previous->next = tmp_next;
			else
				list = tmp_next;
			ft_lstdelone(&tmp, free_lst);
			tmp = tmp_next;
		}
		else
		{
			tmp_previous = tmp;
			tmp = tmp->next;
		}
	}
	return (list);
}

t_list		*ft_r(t_list *list)
{
	return (ft_lstrev(list));
}

t_list		*ft_t(t_list *list)
{
	lstsort(&list, cmp_time, 1);
	return (list);
}
