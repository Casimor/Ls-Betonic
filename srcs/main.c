/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:57 by ochase            #+#    #+#             */
/*   Updated: 2015/01/29 15:00:50 by bboumend         ###   ########.fr       */
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
	ft_ls(&opt, &data);
	return (0);
}
