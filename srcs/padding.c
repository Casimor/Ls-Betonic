/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 22:34:30 by ochase            #+#    #+#             */
/*   Updated: 2015/02/01 22:34:51 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
