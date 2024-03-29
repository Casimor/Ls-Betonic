/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursiv_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:18:40 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/05 17:10:37 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define TMP_INFO ((t_info*)tmp->content)

void		free_lst(void *lst, size_t i)
{
	(void)i;
	free(((t_info*)lst)->mode);
	free(((t_info*)lst)->name);
	free(((t_info*)lst)->link);
	free(((t_info*)lst)->usr);
	free(((t_info*)lst)->grp);
	free(((t_info*)lst)->size);
	free(((t_info*)lst)->time);
	free(((t_info*)lst)->link_info);
	free(((t_info*)lst)->path);
	free(((t_info*)lst));
}

void		get_dir_list(t_list **list)
{
	t_list		*tmp;
	t_list		*tmp_next;
	t_list		*tmp_previous;

	tmp = *list;
	tmp_previous = NULL;
	while (tmp)
	{
		if (TMP_INFO->mode[0] != 'd' || !ft_strcmp(TMP_INFO->name, ".") ||
			!ft_strcmp(TMP_INFO->name, ".."))
		{
			tmp_next = tmp->next;
			if (tmp_previous)
				tmp_previous->next = tmp_next;
			else
				*list = tmp_next;
			ft_lstdelone(&tmp, free_lst);
			tmp = tmp_next;
		}
		else
		{
			tmp_previous = tmp;
			tmp = tmp->next;
		}
	}
}
