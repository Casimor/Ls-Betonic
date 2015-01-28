/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 13:39:45 by gudepard          #+#    #+#             */
/*   Updated: 2015/01/28 12:34:49 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	insert_comparator(void *c, size_t c_s, void *n, size_t n_s)
{
	t_map_entry	*c_entry;
	t_map_entry	*n_entry;

	UNUSED(c_s);
	UNUSED(n_s);
	c_entry = (t_map_entry *)c;
	n_entry = (t_map_entry *)n;
	return (c_entry->hash_ - n_entry->hash_);
}

void		ft_map_insert(t_map map, t_map_entry entry, t_simple_hash_func h_f)
{
	t_tree	*node;

	entry.hash_ = h_f(entry.key);
	node = ft_tree_new(&entry, sizeof(t_map_entry));
	ft_tree_insert(&map[entry.hash_ % MAP_TREE_SIZE], node, insert_comparator);
}
