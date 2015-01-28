/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/24 14:02:37 by bchevali          #+#    #+#             */
/*   Updated: 2014/10/01 14:38:17 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_sort_ls(char **f_tab)
{
	char	*tmp;
	int		a;
	int		i;
	int		j;

	j = 0;
	a = -1;
	while (f_tab[++a])
	{
		i = a + 1;
		while (f_tab[i])
		{
			while (f_tab[a][j] == f_tab[i][j])
				j++;
			if (f_tab[a][j] > f_tab[i][j])
			{
				tmp = f_tab[a];
				f_tab[a] = f_tab[i];
				f_tab[i] = tmp;
			}
			j = 0;
			i++;
		}
	}
	return (f_tab);
}

int		ft_readlen(char *dir)
{
	struct dirent	*f_read;
	DIR				*ret;
	int				i;

	i = 0;
	f_read = NULL;
	ret = NULL;
	ret = opendir(dir);
	if (ret == NULL)
	{
		ft_putstr_fd("./ft_ls: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (-1);
	}
	while ((f_read = readdir(ret)))
		i++;
	return (i);
}

char	**ft_ls(char *dir)
{
	struct dirent	*f_read;
	DIR				*ret;
	char			**f_tab;
	int				i;

	ret = NULL;
	f_read = NULL;
	i = ft_readlen(dir) + 1;
	if (i == 0)
		return (0);
	f_tab = (char**)malloc(sizeof(char*) * i);
	f_tab[i] = NULL;
	if (f_tab)
	{
		i = 0;
		ret = opendir(dir);
		while ((f_read = readdir(ret)))
		{
			f_tab[i] = ft_strdup(f_read->d_name);
			i++;
		}
		closedir(ret);
	}
	return (ft_sort_ls(f_tab));
}
