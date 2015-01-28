/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:18:09 by ochase            #+#    #+#             */
/*   Updated: 2013/12/05 19:51:23 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setcolor(unsigned char color)
{
	char	*color_str;

	color_str = ft_itoa(color);
	ft_putstr("\033[38;5;");
	ft_putstr(color_str);
	ft_putchar('m');
	free(color_str);
}
