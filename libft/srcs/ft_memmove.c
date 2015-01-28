/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:35:25 by ochase            #+#    #+#             */
/*   Updated: 2013/12/02 19:04:23 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		index;
	char				*dest2;
	const char			*src2;
	char				*copy;

	index = 0;
	dest2 = dest;
	src2 = src;
	copy = ft_memalloc(n);
	while (index < n)
	{
		copy[index] = src2[index];
		index++;
	}
	index = 0;
	while (index < n)
	{
		dest2[index] = copy[index];
		index++;
	}
	free(copy);
	return (dest);
}
