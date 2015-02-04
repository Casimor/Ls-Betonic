/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:32:15 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/04 19:11:12 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_ls(t_list *lst)
{
	while (lst)
	{
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
			ft_print_ls(lst);
		ft_putchar('\n');
	}
	else
	{
		if (opt->g_flag)
			print_gopt(lst, opt);
		else if (opt->l_flag)
			print_lopt(lst, opt);
		else
			ft_print_ls(lst);
	}
}
