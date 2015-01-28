/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:38:07 by ochase            #+#    #+#             */
/*   Updated: 2013/11/25 18:36:00 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	size_t		i;

	i = ft_strlen(s2);
	while (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		if (!ft_strncmp(s1, s2, i))
			return ((char *)s1);
		++s1;
	}
	return (0);
}
