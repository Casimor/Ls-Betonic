/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 18:36:11 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/17 21:48:06 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_sort(char *s1, char *s2)
{
	int		c;

	c = 0;
	while (s1[c] && s2[c])
	{
		if (s1[c] > s2[c])
			return (1);
		c++;
	}
	if (s1[c])
		return (1);
	else
		return (0);
}

void		sort_lst(t_list *err_lst)
{
	t_files	*files;
	t_files	*files_n;
	t_files	*tmp;
	t_list	*err_lst_n;

	while (err_lst)
	{
		err_lst_n = err_lst->next;
		files = err_lst->content;
		while (err_lst_n)
		{
			files_n = err_lst_n->content;
			if (is_sort(files->name, files_n->name))
			{
				tmp = err_lst->content;
				err_lst->content = err_lst_n->content;
				err_lst_n->content = tmp;
			}
			err_lst_n = err_lst_n->next;
		}
		err_lst = err_lst->next;
	}
}

void		display_error(t_list *err_lst)
{
	t_files	*files;

	if (!err_lst)
		return ;
	sort_lst(err_lst);
	while (err_lst)
	{
		files = err_lst->content;
		ft_putstr_fd("ls: ", 2);
		perror(files->name);
		err_lst = err_lst->next;
	}
}
