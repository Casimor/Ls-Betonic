/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 12:04:24 by ochase            #+#    #+#             */
/*   Updated: 2015/01/28 12:43:34 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	map_foreach(t_tree *root, t_simple_functor functor, void *data)
{
	if (root)
	{
		functor(root->content, data);
		map_foreach(root->left, functor, data);
		map_foreach(root->right, functor, data);
	}
}

void		ft_map_foreach(t_map map, t_simple_functor functor, void *data)
{
	size_t	i;

	i = 0;
	while (i < MAP_TREE_SIZE)
		map_foreach(map[i++], functor, data);
}
