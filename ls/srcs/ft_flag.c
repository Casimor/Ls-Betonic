/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/29 17:32:26 by bchevali          #+#    #+#             */
/*   Updated: 2014/10/01 12:56:04 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_parse_flag(char *opt)
{
	int		i;
	int		a;
	int		r;

	i = 1;
	a = 0;
	r = 0;
	while (opt[i])
	{
		if (opt[i] == 'a' && a == 0)
			a = 1;
		else if (opt[i] == 'r' && r == 0)
			r = 1;
		else if (opt[i] != 'a' && opt[i] != 'r')
		{
			ft_putstr_fd("./ft_ls: illegal option -- ", 2);
			ft_putchar_fd(opt[i], 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
		i++;
	}
	return (1);
}
