/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:47:00 by ochase            #+#    #+#             */
/*   Updated: 2014/01/06 21:56:37 by ochase           ###   ########.fr       */
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

char			*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				j;
	long int		n1;
	long int		n2;

	n1 = NNB(n);
	n2 = n;
	n2 = NNB(n2);
	i = 0;
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / 10;
	n >= 0 ? i : (i = i + 1);
	str = ft_memalloc(i + 1);
	j = i - 1;
	ft_if_n_is_null(n, str);
	while (n2 != 0)
	{
		str[j--] = n2 % 10 + 48;
		n2 = n2 / 10;
	}
	str[i + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
