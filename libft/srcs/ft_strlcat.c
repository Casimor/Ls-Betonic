/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:37:03 by ochase            #+#    #+#             */
/*   Updated: 2013/11/25 19:20:08 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	c;
	unsigned int	i;

	i = ft_strlen(src);
	c = ft_strlen(dest);
	if (c >= size)
		return (size + i);
	ft_strncat(dest + c, src, size - c - 1);
	return (c + i);
}
