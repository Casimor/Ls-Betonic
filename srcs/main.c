/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 11:31:10 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"

int		main(int argc, char **argv)
{
	t_dirent		*dirent;
	DIR				*dir;
	t_list			*list;
	t_info			*info;

	(void)argc;
	parser(argv);
	list = NULL;
	dir = opendir (".");
	while ((dirent = readdir(dir)))
	{
		if (dirent->d_name[0] != '.')
		{
			info = ft_new_info(dirent, ".");
			ft_lstsort(&list, info, ft_cmp_lexico, 0);
		}
	}
	closedir (dir);
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
	return (0);
}
