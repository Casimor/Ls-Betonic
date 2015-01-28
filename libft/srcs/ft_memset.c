/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:07:48 by ochase            #+#    #+#             */
/*   Updated: 2013/11/25 17:28:26 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	i;
	unsigned int	j;
	unsigned char	*str;

	j = 0;
	i = c;
	str = s;
	while (j < n)
	{
		str[j] = i;
		j++;
	}
	return (str);
}
