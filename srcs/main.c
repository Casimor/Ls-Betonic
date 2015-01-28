/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 18:27:01 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt	opt;
	t_list	*n_dir;
	size_t	nb_dir;

	(void)argc;
	n_dir = parser(argv);
	nb_dir = ft_lstsize(&index);
	while (n_dir->next)
	{	
		ft_ls(n_dir->content, opt, nb_dir);
		n_dir = n_dir->next;
	}
	return (0);
}
