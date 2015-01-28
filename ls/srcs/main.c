/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 12:23:19 by bchevali          #+#    #+#             */
/*   Updated: 2014/10/01 14:39:07 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static const t_opt	g_tab[] = {
	{"-ar", ft_printr_ls},
	{"-ra", ft_printr_ls},
	{"-r", ft_printr_ls},
	{"-a", ft_print_ls}};

int		ft_check_opt(char *line, char **f_tab)
{
	size_t		i;

	i = 0;
	while (i < sizeof(g_tab) / sizeof(t_opt))
	{
		if ((ft_strcmp(g_tab[i].str, line)) == 0)
		{
			g_tab[i].f(f_tab, line);
			return (1);
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	**f_tab;
	int		i;

	i = 1;
	(void)ac;
	if (av[1] && av[i][0] == '-' && av[i][1])
	{
		if (!ft_parse_flag(av[1]))
			return (0);
		i++;
	}
	if (!av[i])
		av[i] = ".";
	if ((f_tab = ft_ls(av[i])) == 0)
		return (0);
	if (av[1][0] == '-')
		ft_check_opt(av[1], f_tab);
	else
		ft_print(f_tab);
	return (0);
}
