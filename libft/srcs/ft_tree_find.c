/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:11:14 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 12:34:47 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_tree_find(t_tree *node, void *n, size_t s, t_comparator cmp)
{
	int	cmp_value;

	if (node)
	{
		cmp_value = cmp(node->content, node->content_size, n, s);
		if (!cmp_value)
			return (node);
		if (cmp_value > 0)
			return (ft_tree_find(node->right, n, s, cmp));
		return (ft_tree_find(node->left, n, s, cmp));
	}
	return (0);
}
