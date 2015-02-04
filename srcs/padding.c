/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 22:34:30 by ochase            #+#    #+#             */
/*   Updated: 2015/02/04 23:22:17 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		set_padding_major_minor(char *content, t_size *max)
{
	char	**maj_min;
	char	*str;
	size_t	i;
	size_t	n;

	i = 1;
	n = 0;
	maj_min = ft_strsplit(content, ',');
	str = ft_memalloc(max->major + max->minor + 5);
	str[0] = ' ';
	while (i <= max->major)
	{
		if (i <= (max->major - ft_strlen(maj_min[0])))
			str[i++] = ' ';
		else
			str[i++] = maj_min[0][n++];
	}
	str[i++] = ',';
	str[i++] = ' ';
	n = 0;
	while (i <= (max->major + max->minor + 2))
	{
		if (i <= ((max->major + max->minor + 2) - ft_strlen(maj_min[1])))
			str[i++] = ' ';
		else
			str[i++] = maj_min[1][n++];
	}
	str[i] = ' ';
	ft_putstr(str);
	free(str);
}

void		set_padding_nbr(char *content, size_t size)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	str = ft_memalloc(size + 2);
	while (i < (size - ft_strlen(content)))
		str[i++] = ' ';
	while (n < ft_strlen(content))
		str[i++] = content[n++];
	str[i] = ' ';
	ft_putstr(str);
	free(str);
}

void		set_padding(char *content, size_t size, size_t end_space)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_memalloc(size + end_space + 1);
	while (content[i] != '\0')
	{
		str[i] = content[i];
		i++;
	}
	while (i < (size + end_space))
		str[i++] = ' ';
	ft_putstr(str);
	free(str);
}
