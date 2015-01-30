/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/01/30 14:05:17 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_opt	opt;
	t_ldata	data;

	(void)argc;
	parser(argv, &opt, &data);
	ft_ls(&opt, &data);
	return (0);
}
