/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 22:14:19 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_opt	opt;
	t_ldata	data;

	(void)argc;
	parser(argv, &opt, &data);
	// while (n_dir)
	// {
		// ft_ls((char *)data->content, &opt);
	// }
	return (0);
}
