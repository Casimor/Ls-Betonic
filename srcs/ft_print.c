/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:32:15 by bchevali          #+#    #+#             */
/*   Updated: 2015/01/30 14:11:21 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_ls(t_opt *opt, t_list *list)
{
	if (opt->r_flag == 1)
		list = ft_lstrev(list);
	while (list)
	{
		if (opt->r_flag == 1)
		{
			if (((t_info *)(list->content))->name[0] != '.' || opt->a_flag == 1)
			{
				ft_putstr(((t_info *)(list->content))->name);
				ft_putchar('\n');
			}
		}
		else if (((t_info *)(list->content))->name[0] != '.' || opt->a_flag == 1)
		{
			ft_putstr(((t_info *)(list->content))->name);
			ft_putchar('\n');
		}
		list = list->next;
	}
}

size_t		ft_print(t_opt *opt, t_list *list, char *name, size_t nb_files)
{
	if (nb_files > 1)
	{
		ft_putstr(name);
		ft_putendl(":");
		ft_print_ls(opt, list);
		ft_putchar('\n');
		nb_files--;
	}
	else
		ft_print_ls(opt, list);
	return (nb_files);
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
