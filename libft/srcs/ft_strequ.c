/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:40:40 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 16:25:26 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strequ("a", "a") -> 1
** ft_strequ("a", "b") -> 0
** ft_strequ(NULL, NULL) -> 1
** ft_strequ("a", NULL) -> 0
** ft_strequ(NULL, "a") -> 0
*/

int		ft_strequ(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (1);
	else if (!s2 ^ !s1)
		return (0);
	return (!ft_strcmp(s1, s2));
}
