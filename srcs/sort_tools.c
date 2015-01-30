/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:13:42 by bboumend          #+#    #+#             */
/*   Updated: 2015/01/30 19:21:31 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_r(t_list *list, t_info *info)
{
	ft_lstsort(&list, info, ft_cmp_lexico, 1);
	return (list);
}

t_list		*ft_a(t_list *list, t_info *info)
{
	ft_lstsort(&list, info, ft_cmp_lexico, 0);
	return (list);
}

t_list		*ft_l(t_list *list, t_info *info)
{
	ft_lstsort(&list, info, ft_cmp_lexico, 0);
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
		ft_putchar('\n');
		list = list->next;
	}

t_list		*ft_t(t_list *list, t_info *info)
{
	ft_lstsort(&list, info, ft_cmp_time, 0);
	return (list);
}
