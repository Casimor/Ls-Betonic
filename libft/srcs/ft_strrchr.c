/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:37:26 by ochase            #+#    #+#             */
/*   Updated: 2013/11/22 19:19:10 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = c;
	i = 0;
	while (s[i])
		i++;
	while (i != 0)
	{
		if (s[i] == cc)
			return ((char*)&s[i]);
		i--;
	}
	if (s[i] == cc)
		return ((char*)&s[i]);
	return (NULL);
}
