/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:38:46 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 17:29:56 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_atoi_ignored(char c)
{
	return (c == '\n'
	|| c == '\v'
	|| c == '\t'
	|| c == '\r'
	|| c == '\f'
	|| c == ' ');
}

int			ft_atoi(const char *str)
{
	int		c;
	int		i;

	c = 0;
	i = 0;
	if (str == '\0')
		return (0);
	while (is_atoi_ignored(*str))
		++str;
	if (str[0] == '-' || str[0] == '+')
		c = 1;
	while (str[c] != '\0' && (str[c] >= '0' && str[c] <= '9'))
	{
		i = i * 10 + str[c] - '0';
		c = c + 1;
	}
	if (str[0] == '-')
		return (-i);
	return (i);
}
