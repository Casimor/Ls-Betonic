/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:01:39 by ochase            #+#    #+#             */
/*   Updated: 2015/01/29 21:44:05 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"

static char		perm_type(struct stat *cc)
{
	if (S_ISBLK(cc->st_mode))
		return ('b');
	if (S_ISCHR(cc->st_mode))
		return ('c');
	if (S_ISDIR(cc->st_mode))
		return ('d');
	if (S_ISFIFO(cc->st_mode))
		return ('p');
	if (S_ISREG(cc->st_mode))
		return ('-');
	if (S_ISLNK(cc->st_mode))
		return ('l');
	if (S_ISSOCK(cc->st_mode))
		return ('s');
	if (S_ISWHT(cc->st_mode))
		return ('w');
	return ('?');
}

char		*permissions(struct stat *cp)
{
	char			*str;

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
		str[10] = ' ';
	}
	return (str);
}
