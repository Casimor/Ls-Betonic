/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:39:35 by bboumend          #+#    #+#             */
/*   Updated: 2015/01/30 19:17:52 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list		*sort_list(t_list *list, t_info *info, t_opt *opt)
{
	size_t			i;
	size_t			c;
	const t_sort	flag_tab[] = {
		// {"t", ft_t},
		// {"l", ft_l},
		// {"e", ft_e},
		{opt->r_flag, ft_r}};

	i = 0;
	c = 0;
	while (i < sizeof(flag_tab) / sizeof(t_sort))
	{
		if (flag_tab[i].flag == 1)
		{
			c = 1;
			list = flag_tab[i].f(list, info);
		}
		i++;
	}
	if (!c)
		ft_lstsort(&list, info, ft_cmp_lexico, 0);
	return (list);
}

void				display(t_opt *opt, t_files *files, size_t i)
{
	t_list			*list;
	t_dirent		*dirent;

	list = NULL;
	while ((dirent = readdir(files->dir)))
		list = sort_list(list, new_info(dirent, files->name), opt);
	ft_print(opt, list, files->name, i);
}

// display(opt, new_info(dirent, files->name), files->name);
// 
// while ((dit = readdir(files->dir)))
// {
    // if (opt->t_flag == 1)
        // ft_lstsort(&list, new_info(dit, files->name), ft_cmp_time, 0);
    // else
        // ft_lstsort(&list, new_info(dit, files->name), ft_cmp_lexico, 0);