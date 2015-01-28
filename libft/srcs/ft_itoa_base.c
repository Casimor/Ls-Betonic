/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:47:00 by ochase            #+#    #+#             */
/*   Updated: 2014/01/06 21:56:48 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_if_n_is_null(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (0);
}

char			*ft_itoa_base(size_t n, char *base)
{
	char			*str;
	int				i;
	int				j;
	long int		n1;
	int				b;

	n1 = n;
	i = 0;
	b = ft_strlen(base);
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / b;
	str = ft_memalloc(i + 1);
	j = i - 1;
	ft_if_n_is_null(n, str);
	while (n != 0)
	{
		str[j--] = base[n % b];
		n = n / b;
	}
	str[i + 1] = '\0';
	return (str);
}
