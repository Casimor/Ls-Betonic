/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delet_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 21:44:57 by ochase            #+#    #+#             */
/*   Updated: 2014/02/10 18:18:38 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tree(t_tree *top, t_deleter del)
{
	if (top)
	{
		free_tree(top->left, del);
		free_tree(top->right, del);
		del(top->content, top->content_size);
		free(top);
	}
}

void		ft_tree_delet(t_tree **root, t_deleter del)
{
	t_tree	*top;

	top = *root;
	if (top)
	{
		free_tree(top, del);
		*root = 0;
	}
}
