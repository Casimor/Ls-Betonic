/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:34:50 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 15:21:29 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int					i;
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;
	unsigned char		uc;

	i = 0;
	dest_cpy = dest;
	src_cpy = src;
	uc = c;
	while (n != 0)
	{
		dest_cpy[i] = src_cpy[i];
		if (src_cpy[i] == uc)
			return (dest_cpy + i + 1);
		i++;
		n--;
	}
	return (0);
}
