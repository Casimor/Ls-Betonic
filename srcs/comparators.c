/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 18:12:02 by ochase            #+#    #+#             */
/*   Updated: 2015/02/01 18:35:42 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cmp_lexico(const t_info *info1, const t_info *info2, int rev)
{
	if (rev)
		return (-ft_strcmp(info1->name, info2->name));
	return (ft_strcmp(info1->name, info2->name));
}

int		cmp_time(const t_info *info1, const t_info *info2, int rev)
{
	int		result;

	if (info1->timesec.tv_sec == info2->timesec.tv_sec)
		result = info2->timesec.tv_nsec - info1->timesec.tv_nsec;
	else
		result = info2->timesec.tv_sec - info1->timesec.tv_sec;
	if (rev)
		return (-result);
	return (result);
}
