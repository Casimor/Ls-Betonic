/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 14:55:36 by bchevali          #+#    #+#             */
/*   Updated: 2014/10/01 14:18:38 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putendl(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_printr_ls(char **f_tab, char *opt)
{
	int		i;

	i = 0;
	while (f_tab[i])
		i++;
	i -= 1;
	while (i >= 0)
	{
		if (opt[1] == 'a' || opt[2] == 'a')
			ft_putendl(f_tab[i]);
		else if (f_tab[i][0] != '.')
			ft_putendl(f_tab[i]);
		i--;
	}
}

void	ft_print_ls(char **f_tab, char *opt)
{
	int		i;

	i = 0;
	if (opt[2] == 'r' || opt[1] == 'r')
		ft_printr_ls(f_tab, opt);
	else
	{
		while (f_tab[i])
		{
			if (opt[1] == 'a' || opt[2] == 'a')
				ft_putendl(f_tab[i]);
			else if (f_tab[i][0] != '.')
				ft_putendl(f_tab[i]);
			i++;
		}
	}
}

void	ft_print(char **f_tab)
{
	int		i;

	i = 0;
	while (f_tab[i])
	{
		if (f_tab[i][0] != '.')
			ft_putendl(f_tab[i]);
		i++;
	}
}
