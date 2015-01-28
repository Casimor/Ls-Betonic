/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:32:15 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/28 19:17:14 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print(t_opt *opt, t_list *list)
{
	(void)opt;
	while (list)
	{
		ft_putstr((char*)list->content);
		// ft_putstr(((t_info *)(list->content))->mode);
		// ft_putchar('\t');
		// ft_putstr(((t_info *)(list->content))->link);
		// ft_putchar('\t');
		// ft_putstr(((t_info *)(list->content))->usr);
		// ft_putchar('\t');
		// ft_putstr(((t_info *)(list->content))->grp);
		// ft_putchar('\t');
		// ft_putstr(((t_info *)(list->content))->size);
		// ft_putchar('\t');
		// ft_putstr(((t_info *)(list->content))->time);
		// ft_putchar('\t');
		// ft_putstr(((t_info *)(list->content))->name);
		ft_putchar('\n');
		list = list->next;
	}
}