/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:32:15 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/30 19:16:57 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_ls(t_opt *opt, t_list *lst)
{
	while (lst)
	{
		if (!opt->a_flag && ((t_info *)(lst->content))->name[0] == '.')
		{
			lst = lst->next;
			continue ;
		}
		ft_putendl(((t_info *)(lst->content))->name);
		lst = lst->next;
	}
}

void		ft_print(t_opt *opt, t_list *lst, char *name, size_t s_file)
{
	if (s_file > 1)
	{
		ft_putstr(name);
		ft_putendl(":");
		ft_print_ls(opt, lst);
		ft_putchar('\n');
	}
	else
		ft_print_ls(opt, lst);
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
