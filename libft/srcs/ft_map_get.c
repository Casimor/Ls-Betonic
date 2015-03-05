/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:01:42 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 12:43:34 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			hash_cmp(void *c, size_t c_s, void *n, size_t n_s)
{
	t_map_entry		*c_entry;
	t_uint64		*p_hash;

	UNUSED(c_s);
	UNUSED(n_s);
	c_entry = (t_map_entry *)c;
	p_hash = (t_uint64 *)n;
	return (c_entry->hash_ - *p_hash);
}

static t_map_entry	*get(t_tree *node, t_uint64 hash)
{
	t_tree			*found;

	found = ft_tree_find(node, &hash, 0, hash_cmp);
	if (found)
		return ((t_map_entry *)found->content);
	return (0);
}

void				*ft_map_get(t_map map, void *key, t_simple_hash_func h_f)
{
	t_map_entry		*entry;

	entry = ft_map_get_p(map, key, h_f);
	if (entry)
		return (entry->value);
	return (0);
}

t_map_entry			*ft_map_get_p(t_map map, void *key, t_simple_hash_func h_f)
{
	t_map_entry		*entry;
	t_uint64		hash;

	hash = h_f(key);
	entry = get(map[hash % MAP_TREE_SIZE], hash);
	return (entry);
}
