/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:35:38 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 12:34:50 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	insert(t_tree *r, t_tree *n, t_comparator cmp)
{
	if (cmp(r->content, r->content_size, n->content, n->content_size) < 0)
	{
		if (!r->left)
			r->left = n;
		else
			insert(r->left, n, cmp);
	}
	else
	{
		if (!r->right)
			r->right = n;
		else
			insert(r->right, n, cmp);
	}
}

void		ft_tree_insert(t_tree **root, t_tree *node, t_comparator cmp)
{
	if (!*root)
		*root = node;
	else
		insert(*root, node, cmp);
}
