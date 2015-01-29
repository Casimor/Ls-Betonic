/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 14:08:52 by ochase            #+#    #+#             */
/*   Updated: 2015/01/29 19:04:07 by bchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *lst)
{
	t_list	*out;
	t_list	*it;

	it = lst;
	out = NULL;
	while (it)
	{
		ft_lstadd(&out, ft_lstnew(it->content, it->content_size));
		it = it->next;
	}
	return (out);
}
