/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 22:50:12 by ochase            #+#    #+#             */
/*   Updated: 2014/01/25 23:04:15 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*strnew_zero(void)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int			fill_split(const char *s, char **str, int *c)
{
	if (s[c[2] - 1] == '+' || s[c[2] - 1] == '-')
		str[c[1]] = strnew_zero();
	else
		str[c[1]] = ft_strsub(s, c[3], (c[2] - c[3]));
	c[1]++;
	return (c[1]);
}
