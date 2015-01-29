/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 15:03:44 by ochase            #+#    #+#             */
/*   Updated: 2015/01/29 16:33:33 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	illegal_option_error(char *cmd)
{
	ft_putstr("ls: illegal option -- ");
	ft_putstr(cmd);
	ft_putstr("\nusage: ls [-lartR] [file ...]\n");
	exit(0);
}

void	fts_error(void)
{
	ft_putstr("ls: fts_open: No such file or directory\n");
	exit(0);
}
