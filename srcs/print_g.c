/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:49:06 by bchevali          #+#    #+#             */
/*   Updated: 2015/02/04 19:21:31 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print(t_list *list, t_size *max)
{
	while (list)
	{
		set_padding(((t_info *)(list->content))->mode, max->mode, 1);
		set_padding_nbr(((t_info *)(list->content))->link, max->link);
		set_padding(((t_info *)(list->content))->grp, max->group, 2);
		set_padding_nbr(((t_info *)(list->content))->size, max->fsize);
		set_padding(((t_info *)(list->content))->time,
			ft_strlen(((t_info *)(list->content))->time), 1);
		set_padding(((t_info *)(list->content))->name,
			ft_strlen(((t_info *)(list->content))->name), 0);
		if (((t_info *)(list->content))->link_info)
		{
			ft_putstr(" -> ");
			set_padding(((t_info *)(list->content))->link_info,
				ft_strlen(((t_info *)(list->content))->link_info), 0);
		}
		ft_putchar('\n');
		list = list->next;
	}
}

static size_t	get_total(t_list *list)
{
	size_t	total;

	total = 0;
	while (list)
	{
		total += ((t_info *)(list->content))->blocks;
		list = list->next;
	}
	return (total);
}

static size_t	find_max_size(t_list *list, size_t mem_offset)
{
	size_t	cur_len;
	size_t	max;

	max = 0;
	while (list)
	{
		cur_len = ft_strlen(*((char**)((char*)(list->content) + mem_offset)));
		if (cur_len > max)
			max = cur_len;
		list = list->next;
	}
	return (max);
}

void			print_gopt(t_list *list)
{
	t_size	max;
	size_t	total;

	max.mode = find_max_size(list, sizeof(char*) * 0);
	max.link = find_max_size(list, sizeof(char*) * 1);
	max.group = find_max_size(list, sizeof(char*) * 3);
	max.fsize = find_max_size(list, sizeof(char*) * 4);
	total = get_total(list);
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	print(list, &max);
}
