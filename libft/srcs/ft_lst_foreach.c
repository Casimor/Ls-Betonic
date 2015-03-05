/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:28:22 by ochase            #+#    #+#             */
/*   Updated: 2014/01/10 15:56:22 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_foreach(t_list *list, t_listf f, void *data)
{
	if (list)
	{
		while (list)
		{
			f(list, data);
			list = list->next;
		}
	}
}
