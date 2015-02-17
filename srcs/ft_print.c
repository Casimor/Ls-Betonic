/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:32:15 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/17 20:01:32 by bchevali         ###   ########.fr       */
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

void		print_files(t_list *files, t_ldata *data)
{
	if (!files)
		return ;
	lstsort(&files, cmp_files, 1);
	while (files)
	{
		ft_putstr((char*)(files->content));
		if (files->next)
			ft_putchar(' ');
		files = files->next;
	}
	if (data->file_lst)
		ft_putchar('\n');
	ft_putchar('\n');
}

void		print_perm_denied(t_list *list, char *name, size_t i)
{
	if (i > 1)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	while (list)
	{
		ft_putstr_fd("ls: ", 2);
		perror((char*)(list->content));
		list = list->next;
	}
	if (i > 1)
		ft_putchar('\n');
}

void		ft_print(t_opt *opt, t_list *lst, char *name, size_t s_file)
{
	if (s_file > 1)
	{
		ft_putstr(name);
		ft_putendl(":");
		if (opt->l_flag)
			print_lopt(lst);
		else
			ft_print_ls(lst);
		if (!opt->re_flag)
			ft_putchar('\n');
	}
	else
	{
		if (opt->g_flag)
			print_gopt(lst);
		else if (opt->l_flag)
			print_lopt(lst);
		else
			ft_print_ls(lst);
	}
}
