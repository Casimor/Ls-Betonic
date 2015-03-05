/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delone_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 22:02:45 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 12:34:52 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rebuild_tree(t_tree *n, t_tree *rem, t_tree **s, t_comparator cmp)
{
	if (n)
	{
		if (n != rem)
			ft_tree_insert(s, n, cmp);
		rebuild_tree(n->left, rem, s, cmp);
		rebuild_tree(n->right, rem, s, cmp);
	}
}

t_tree		*ft_tree_delone(t_tree **r, void *n, size_t s, t_comparator cmp)
{
	t_tree	*removed;
	t_tree	*new_tree;

	new_tree = 0;
	removed = ft_tree_find(*r, n, s, cmp);
	rebuild_tree(*r, removed, &new_tree, cmp);
	*r = new_tree;
	return (removed);
}
