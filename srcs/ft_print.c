/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:32:15 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/30 15:47:08 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_ls(t_opt *opt, t_list *lst)
{
	if (opt->r_flag == 1)
		lst = ft_lstrev(lst);
	while (lst)
	{
		if (opt->r_flag == 1)
		{
			if (((t_info *)(lst->content))->name[0] != '.' || opt->a_flag == 1)
				ft_putendl(((t_info *)(lst->content))->name);
		}
		else if (((t_info *)(lst->content))->name[0] != '.' || opt->a_flag == 1)
			ft_putendl(((t_info *)(lst->content))->name);
		lst = lst->next;
	}
}

size_t		ft_print(t_opt *opt, t_list *lst, char *name, size_t s_file)
{
	if (s_file > 1)
	{
		ft_putstr(name);
		ft_putendl(":");
		ft_print_ls(opt, lst);
		ft_putchar('\n');
		s_file--;
	}
	else
		ft_print_ls(opt, lst);
	return (s_file);
}



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
