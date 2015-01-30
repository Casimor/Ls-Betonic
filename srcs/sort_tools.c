/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:13:42 by bboumend          #+#    #+#             */
/*   Updated: 2015/01/30 18:06:57 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_r(t_list *list, t_info *info)
{
	ft_lstsort(&list, info, ft_cmp_lexico, 1);
	return (list);
}

t_list		*ft_a(t_list *list, t_info *info)
{
	ft_lstsort(&list, info, ft_cmp_lexico, 0);
	return (list);
}
