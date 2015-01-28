/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 22:08:04 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_opt	opt;
	t_list	*n_dir;

	(void)argc;
	n_dir = parser(argv, &opt);
	while (n_dir)
	{
		ft_ls((char *)n_dir->content, &opt);
		n_dir = n_dir->next;
	}
	return (0);
}
