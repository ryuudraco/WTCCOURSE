/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:05:42 by jheath            #+#    #+#             */
/*   Updated: 2018/09/12 16:58:30 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir		*ft_new(char *file, char *p)
{
	struct stat s;
	t_dir		*elem;

	elem = malloc(sizeof(t_dir));
	elem->file = ft_strdup(file);
	elem->dpath = ft_strjoin(p, file);
	if (stat(elem->dpath, &s) == -1)
		ft_putstr("Stat Error\n");
	elem->pms = permissions(s, elem);
	elem->hlnk = s.st_nlink;
	elem->uid = uid(s);
	elem->gid = gid(s);
	elem->size = s.st_size;
	elem->date = get_time(s);
	elem->mdate = s.st_mtime;
	elem->blcks = s.st_blocks;
	elem->next = NULL;
	return (elem);
}

void		elemf(t_dir **elem, char *file, char *p)
{
	t_dir		*list;

	list = *elem;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new(file, p);
	}
	else
		*elem = ft_new(file, p);
}

int			elemd(struct dirent *dirp, t_dir **elem, char *p)
{
	t_dir		*list;

	list = *elem;
	if (!dirp)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_new(dirp->d_name, p);
	}
	else
		*elem = ft_new(dirp->d_name, p);
	return (1);
}