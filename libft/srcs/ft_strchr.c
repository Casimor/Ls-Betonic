/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:37:13 by ochase            #+#    #+#             */
/*   Updated: 2013/11/22 19:18:36 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char*)&s[i]);
	return (NULL);
}
