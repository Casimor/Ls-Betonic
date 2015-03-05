/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:23:24 by ochase            #+#    #+#             */
/*   Updated: 2014/01/24 18:33:35 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_tree_new(void *content, size_t content_size)
{
	t_tree	*new_elem;

	new_elem = malloc(sizeof(t_tree));
	if (new_elem)
	{
		new_elem->content_size = (content ? content_size : 0);
		new_elem->content = (content ? ft_memalloc(content_size) : 0);
		if (new_elem->content)
			ft_memcpy(new_elem->content, content, content_size);
		new_elem->right = NULL;
		new_elem->left = NULL;
	}
	return (new_elem);
}
