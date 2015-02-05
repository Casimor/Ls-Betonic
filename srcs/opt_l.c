/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:39 by ochase            #+#    #+#             */
/*   Updated: 2015/02/05 19:46:20 by ochase           ###   ########.fr       */
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

char			*get_size(t_stat *stat, char *mode)
{
	char	*major;
	char	*minor;
	char	*new;

	if ((mode[0] == 'b') || (mode[0] == 'c'))
	{
		major = ft_itoa(major(stat->st_rdev));
		minor = ft_itoa(minor(stat->st_rdev));
		new = ft_strjoin(major, ",");
		new = ft_strjoin(new, minor);
		free(major);
		free(minor);
		return (new);
	}
	return (ft_itoa(stat->st_size));
}

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
	int		mode;

	mode = cp->st_mode;
	str = ft_strnew(11);
	if (str)
	{
		str[0] = perm_type(cp);
		str[1] = (mode & S_IRUSR ? 'r' : '-');
		str[2] = (mode & S_IWUSR ? 'w' : '-');
		str[3] = third_mode(mode & S_IXUSR, mode & S_ISUID, 's', 'S');
		str[4] = (mode & S_IRGRP ? 'r' : '-');
		str[5] = (mode & S_IWGRP ? 'w' : '-');
		str[6] = third_mode(mode & S_IXGRP, mode & S_ISGID, 's', 'S');
		str[7] = (mode & S_IROTH ? 'r' : '-');
		str[8] = (mode & S_IWOTH ? 'w' : '-');
		str[9] = third_mode(mode & S_IXOTH, mode & S_ISVTX, 't', 'T');
		str[10] = get_additional_infos(path);
	}
	return (str);
}
