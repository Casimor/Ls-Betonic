/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 12:22:51 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 12:34:44 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void rebuild_tree(t_tree *n, t_tree *i, t_tree **r, t_comparator cmp)
{
    t_tree *left;
    t_tree *right;

    if (n)
    {
        left = n->left;
        right = n->right;
        n->left = 0;
        n->right = 0;
        if (n != i)
            ft_tree_insert(r, n, cmp);
        rebuild_tree(left, i, r, cmp);
        rebuild_tree(right, i, r, cmp);
    }
}

t_tree     *ft_tree_remove(t_tree **r, void *n, size_t s, t_comparator cmp)
{
    t_tree *removed;
    t_tree *new_tree;

    new_tree = 0;
    removed = ft_tree_find(*r, n, s, cmp);
    rebuild_tree(*r, removed, &new_tree, cmp);
    *r = new_tree;
    return (removed);
}
