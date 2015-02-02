/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 15:39:35 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/02 14:22:50 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			apply_display_flag(t_list **list, t_opt *opt)
{
	size_t			i;
	const t_sort	flag_tab[] = {
		{opt->t_flag, ft_t},
		// {opt->re_flag, ft_re},
		{opt->r_flag, ft_r}};

	i = 0;
	lstsort(list, cmp_lexico, 1);
	while (i < sizeof(flag_tab) / sizeof(t_sort))
	{
		if (flag_tab[i].flag == 1)
			*list = flag_tab[i].f(*list);
		i++;
	}
}

void				display(t_opt *opt, t_files *files, size_t i)
{
	t_list			*list;
	t_dirent		*dirent;

	list = NULL;
	while ((dirent = readdir(files->dir)))
		lstaddinfo(&list, new_info(dirent, files->name));
	apply_display_flag(&list, opt);
	ft_print(opt, list, files->name, i);
	ft_free_lst(&list);
}
