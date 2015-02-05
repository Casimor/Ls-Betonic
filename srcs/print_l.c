/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 18:39:53 by ochase            #+#    #+#             */
/*   Updated: 2015/02/05 17:41:02 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print(t_list *list, t_size *max)
{
	while (list)
	{
		set_padding(((t_info *)(list->content))->mode, max->mode, 1);
		set_padding_nbr(((t_info *)(list->content))->link, max->link);
		set_padding(((t_info *)(list->content))->usr, max->user, 2);
		set_padding(((t_info *)(list->content))->grp, max->group, 2);

		handle_size(list, max);

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

static void		findmm_max(t_list *list, t_size *max, size_t memoff)
{
	size_t	i[2];
	char	*str;

	ft_bzero(i, sizeof(i));
	while (list)
	{
		if (ft_strchr(*((char**)((char*)(list->content) + memoff)), ','))
		{
			str = ft_strdup(*((char**)((char*)(list->content) + memoff)));
			while (str[i[0]])
			{
				if (str[i[0]] == ',')
				{
					i[1] = i[0];
					if (i[0] > max->major)
						max->major = i[0];
				}
				i[0]++;
			}
			if ((i[0] - i[1]) > max->minor)
				max->minor = i[0] - i[1];
			free(str);
		}
		list = list->next;
	}
}

static size_t	find_max_size(t_list *list, size_t mem_offset)
{
	size_t	cur_len;
	size_t	max;

	max = 0;
	while (list)
	{
		//segfault when number instead of wheel
		cur_len = ft_strlen(*((char**)((char*)(list->content) + mem_offset)));
		if (cur_len > max)
			max = cur_len;
		list = list->next;
	}
	return (max);
}

void			print_lopt(t_list *list)
{
	t_size	max;
	size_t	total;

	ft_bzero(&max, sizeof(t_size));
	max.mode = find_max_size(list, sizeof(char*) * 0);
	max.link = find_max_size(list, sizeof(char*) * 1);
	max.user = find_max_size(list, sizeof(char*) * 2);
	// segfault start point
	max.group = find_max_size(list, sizeof(char*) * 3);
	max.fsize = find_max_size(list, sizeof(char*) * 4);
	findmm_max(list, &max, sizeof(char*) * 4);
	total = get_total(list);
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	print(list, &max);
}
