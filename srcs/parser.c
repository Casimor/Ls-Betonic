/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 11:28:52 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 12:36:10 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	parse_cmd(char *cmd)
{
	(void)cmd;
}

void		parser(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '-')
			parse_cmd(args[i]);
		i++;
	}
}
