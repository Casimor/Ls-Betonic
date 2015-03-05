/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:35:36 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 13:18:15 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	index;
	const char		*str;
	char			c2;

	index = 0;
	str = s;
	c2 = c;
	while (index < n)
	{
		if (str[index] == c2)
			return ((char *)&str[index]);
		index++;
	}
	return (0);
}
