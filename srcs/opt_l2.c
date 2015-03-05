/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 19:45:47 by ochase            #+#    #+#             */
/*   Updated: 2015/02/05 19:46:22 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	third_mode(int cond1, int cond2, char first, char second)
{
	if (cond2)
		return (cond1 ? first : second);
	else
		return (cond1 ? 'x' : '-');
	return ('-');
}
