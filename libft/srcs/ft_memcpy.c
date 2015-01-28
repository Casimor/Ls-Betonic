/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:34:39 by ochase            #+#    #+#             */
/*   Updated: 2013/11/25 17:30:00 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*str;
	const char		*str2;

	str = dest;
	str2 = src;
	i = 0;
	while (n != i)
	{
		str[i] = str2[i];
		i++;
	}
	return (str);
}
