/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:08:01 by ochase            #+#    #+#             */
/*   Updated: 2015/02/01 18:10:20 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*join_path(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;
	char	*str2;

	i = ft_strlen(s1);
	if (s1[i - 1] == '/')
		return (ft_strjoin(s1, s2));
	else
	{
		str = ft_strjoin(s1, "/");
		str2 = ft_strjoin(str, s2);
		free(str);
		return (str2);
	}
}

static char		*get_user_name(uid_t uid)
{
	struct passwd	*get_user;

	if ((get_user = getpwuid(uid)) == 0)
		return (ft_itoa(uid));
	else
		return (ft_strdup(get_user->pw_name));
	return (NULL);
}

static char		*get_grp_name(gid_t gid)
{
	struct group	*get_group;

	get_group = getgrgid(gid);
	if (get_group != NULL)
		return (ft_strdup(get_group->gr_name));
	return (NULL);
}

static char		*get_time(t_time *time2)
{
	char	*date;
	time_t	current_time;

	current_time = time(NULL);
	date = ft_strdup(ctime(&time2->tv_sec) + 4);
	if (((current_time - time2->tv_sec) > SIX_MONTHS)
		|| ((current_time - time2->tv_sec) < -SIX_MONTHS))
		ft_strncpy(date + 7, date + 15, 5);
	date[12] = '\0';
	return (date);
}

t_info			*new_info(t_dirent *dirent, char const *path)
{
	t_info	*new_elem;
	t_stat	stat;
	char	*str;

	new_elem = (t_info*)malloc(sizeof(t_info));
	if (new_elem == NULL)
		return (NULL);
	str = join_path(path, dirent->d_name);
	lstat(str, &stat);
	new_elem->mode = permissions(&stat, str);
	new_elem->link = ft_itoa(stat.st_nlink);
	new_elem->usr = get_user_name(stat.st_uid);
	new_elem->grp = get_grp_name(stat.st_gid);
	new_elem->size = ft_itoa(stat.st_size);
	new_elem->time = get_time(&stat.st_mtimespec);
	new_elem->name = dirent->d_name;
	new_elem->timesec = stat.st_mtimespec;
	new_elem->blocks = stat.st_blocks;
	new_elem->link_info = get_link_infos(str);
	free(str);
	return (new_elem);
}
