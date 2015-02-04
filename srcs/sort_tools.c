/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:13:42 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 15:48:24 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_r(t_list *list)
{
	return (ft_lstrev(list));
}

t_list		*ft_t(t_list *list)
{
	lstsort(&list, cmp_time, 1);
	return (list);
}
