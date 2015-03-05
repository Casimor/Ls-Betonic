/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:12:09 by ochase            #+#    #+#             */
/*   Updated: 2014/01/06 21:57:38 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc(sizeof(char *) * (size + 1));
	if (str == 0)
		return (NULL);
	while (i != size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
