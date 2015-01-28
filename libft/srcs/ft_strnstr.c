/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:38:20 by ochase            #+#    #+#             */
/*   Updated: 2013/12/02 19:08:16 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1 && n >= i)
	{
		if (!ft_strncmp(s1, s2, i))
			return ((char *)s1);
		++s1;
		--n;
	}
	return (0);
}
