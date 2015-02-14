/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 15:03:44 by ochase            #+#    #+#             */
/*   Updated: 2015/02/13 12:02:26 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	illegal_option_error(char *cmd)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(*cmd);
	ft_putstr("\nusage: ls [-lartRfg] [file ...]\n");
	exit(0);
}

int		perm_denied(t_list **list, char *name, t_opt *opt)
{
	t_list		*it;
	t_list		*new_elem;

	if (!opt->a_flag && name[0] == '.')
		return (0);
	new_elem = ft_lstnew(name, ft_strlen(name));
	if (!*list)
	{
		ft_lstpushback(list, new_elem);
		return (1);
	}
	else
	{
		it = *list;
		while (it->next)
			it = it->next;
		it->next = new_elem;
		return (1);
	}
}

void	fts_error(void)
{
	ft_putstr("ls: fts_open: No such file or directory\n");
	exit(0);
}
