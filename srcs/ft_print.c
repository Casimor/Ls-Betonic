/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:32:15 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/03 13:40:02 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_ls(t_opt *opt, t_list *lst)
{
	while (lst)
	{
		if (!opt->f_flag && !opt->a_flag && \
			((t_info *)(lst->content))->name[0] == '.')
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
		if (opt->l_flag)
			print_lopt(lst, opt);
		else
			ft_print_ls(opt, lst);
		ft_putchar('\n');
	}
	else
	{
		if (opt->l_flag)
			print_lopt(lst, opt);
		else
			ft_print_ls(opt, lst);
	}
}
