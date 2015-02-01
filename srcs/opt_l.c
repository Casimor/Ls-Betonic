/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:39 by ochase            #+#    #+#             */
/*   Updated: 2015/02/01 17:52:42 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_bit g_perm[8] = {
	{ S_IFBLK, 'b' },
	{ S_IFCHR, 'c' },
	{ S_IFDIR, 'd' },
	{ S_IFIFO, 'p' },
	{ S_IFREG, '-' },
	{ S_IFLNK, 'l' },
	{ S_IFSOCK, 's' },
	{ S_IFWHT, 'w' }
};

char			*get_link_infos(char const *path)
{
	char	buf[256];

	ft_bzero(buf, 256);
	if (readlink(path, buf, 256) > 0)
		return (ft_strdup(buf));
	return (0);
}

static char		perm_type(t_stat *cc)
{
	size_t	index;

	index = 0;
	while (index < 8)
	{
		if ((cc->st_mode & S_IFMT) == g_perm[index].bit)
			return (g_perm[index].ret);
		index++;
	}
	return ('?');
}

static char		get_additional_infos(char *path)
{
	char	buf[256];

	if (listxattr(path, buf, 256, 0) > 0)
		return ('@');
	if (acl_get_link_np(path, ACL_TYPE_EXTENDED))
		return ('+');
	return (' ');
}

char			*permissions(t_stat *cp, char *path)
{
	char	*str;
	str = ft_strnew(11);

	if (str)
	{
		str[0] = perm_type(cp);
		str[1] = (cp->st_mode & S_IRUSR ? 'r' : '-');
		str[2] = (cp->st_mode & S_IWUSR ? 'w' : '-');
		str[3] = (cp->st_mode & S_IXUSR ? 'x' : '-');
		str[4] = (cp->st_mode & S_IRGRP ? 'r' : '-');
		str[5] = (cp->st_mode & S_IWGRP ? 'w' : '-');
		str[6] = (cp->st_mode & S_IXGRP ? 'x' : '-');
		str[7] = (cp->st_mode & S_IROTH ? 'r' : '-');
		str[8] = (cp->st_mode & S_IWOTH ? 'w' : '-');
		str[9] = (cp->st_mode & S_IXOTH ? 'x' : '-');
		str[10] = get_additional_infos(path);
	}
	return (str);
}
