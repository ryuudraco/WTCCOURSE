/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:18:42 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:51:53 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*permissions(struct stat s, t_dir *elem)
{
	mode_t		p;

	elem->pms = (char*)malloc(sizeof(char) * (10 + 1));
	p = s.st_mode;
	elem->pms[0] = (S_ISBLK(p)) ? 'b' : elem->pms[0];
	elem->pms[0] = (S_ISCHR(p)) ? 'c' : elem->pms[0];
	elem->pms[0] = (S_ISDIR(p)) ? 'd' : elem->pms[0];
	elem->pms[0] = (S_ISFIFO(p)) ? 'p' : elem->pms[0];
	elem->pms[0] = (S_ISLNK(p)) ? 'l' : elem->pms[0];
	elem->pms[0] = (S_ISREG(p)) ? '-' : elem->pms[0];
	elem->pms[0] = (S_ISSOCK(p)) ? 's' : elem->pms[0];
	elem->pms[1] = (p & S_IRUSR) ? 'r' : '-';
	elem->pms[2] = (p & S_IWUSR) ? 'w' : '-';
	elem->pms[3] = (p & S_IXUSR) ? 'x' : '-';
	elem->pms[4] = (p & S_IRGRP) ? 'r' : '-';
	elem->pms[5] = (p & S_IWGRP) ? 'w' : '-';
	elem->pms[6] = (p & S_IXGRP) ? 'x' : '-';
	elem->pms[7] = (p & S_IROTH) ? 'r' : '-';
	elem->pms[8] = (p & S_IWOTH) ? 'w' : '-';
	elem->pms[9] = (p & S_IXOTH) ? 'x' : '-';
	elem->pms[10] = '\0';
	return (elem->pms);
}

char	*uid(struct stat s)
{
	struct passwd	*pwd;

	if ((pwd = getpwuid(s.st_uid)))
		return (pwd->pw_name);
	else
		return (ft_utoa(s.st_uid));
}

char	*gid(struct stat s)
{
	struct group	*grp;

	if ((grp = getgrgid(s.st_gid)))
		return (grp->gr_name);
	else
		return (ft_utoa(s.st_gid));
}

char	*get_time(struct stat s)
{
	char		*r;
	char		*tm;
	time_t		t;

	t = time(NULL);
	tm = ctime(&s.st_mtime);
	r = ft_strsub(tm, 4, 12);
	return (r);
}
