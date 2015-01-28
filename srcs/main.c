/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 19:39:42 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_opt	*opt;
	t_list	*n_dir;
	size_t	nb_dir;

	(void)argc;
	opt = ft_memalloc(sizeof(opt));
	if (!opt)
		return 0;
	n_dir = parser(argv, opt);
	nb_dir = ft_lstsize(&n_dir);
	while (n_dir)
	{
		ft_ls((char *)n_dir->content, opt, nb_dir);
		n_dir = n_dir->next;
	}
	return (0);
}
