/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:58:30 by ochase            #+#    #+#             */
/*   Updated: 2015/01/19 17:28:48 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;

	newlst = NULL;
	while (lst)
	{
		ft_lstpushback(&newlst, f(lst));
		lst = lst->next;
	}
	if (newlst)
		return (newlst);
	return (0);
}
