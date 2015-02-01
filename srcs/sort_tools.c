/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:13:42 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/01 19:39:40 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_r(t_list *list)
{
	lstsort(&list, cmp_lexico, 0);
	return (list);
}

t_list		*ft_l(t_list *list)
{
	lstsort(&list, cmp_lexico, 1);
	while (list)
	{
		ft_putstr(((t_info *)(list->content))->mode);
		ft_putchar('\t');
		ft_putstr(((t_info *)(list->content))->link);
		ft_putchar('\t');
		ft_putstr(((t_info *)(list->content))->usr);
		ft_putchar('\t');
		ft_putstr(((t_info *)(list->content))->grp);
		ft_putchar('\t');
		ft_putstr(((t_info *)(list->content))->size);
		ft_putchar('\t');
		ft_putstr(((t_info *)(list->content))->time);
		ft_putchar('\t');
		ft_putstr(((t_info *)(list->content))->name);
		if (((t_info *)(list->content))->link_info)
		{
			ft_putstr(" -> ");
			ft_putstr(((t_info *)(list->content))->link_info);
		}
		ft_putchar('\n');
		list = list->next;
	}
	return (list);
}

t_list		*ft_t(t_list *list)
{
	lstsort(&list, cmp_time, 1);
	return (list);
}
