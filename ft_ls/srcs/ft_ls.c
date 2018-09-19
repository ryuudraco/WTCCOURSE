/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:59:53 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:51:53 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_pfile(t_dir *elem, t_flg option)
{
	t_dir		*cd;

	cd = elem;
	cd = sort_lst(cd, option);
	(option.l == 1 || option.g == 1) ? ls_long(cd, option) : ls_std(cd, option);
	option.rcr == 1 ? recursive(cd, option) : NULL;
}

void	ls_pdir(t_dir *elem, t_flg option, int mdir)
{
	DIR			*dir;
	t_dir		*data;
	int			nl;

	data = NULL;
	nl = 0;
	while (elem)
	{
		dir = opendir(elem->file);
		while (elemd(readdir(dir), &data, ft_strjoin(elem->dpath, "/")) != 0)
			;
		closedir(dir);
		if (data)
		{
			nl == 1 ? ft_putchar('\n') : NULL;
			nl = 1;
			mdir ? ft_putendl(ft_strcat(elem->file, ":")) : 0;
			ls_pfile(data, option);
		}
		data = NULL;
		elem = elem->next;
	}
}

void	ls_dir(t_list *p, t_flg option, int mdir)
{
	t_list		*cd;
	t_dir		*elem;

	cd = p;
	elem = NULL;
	while (cd)
	{
		elem = elemf(elem, cd->data, "");
		cd = cd->next;
	}
	elem = sort_lst(elem, option);
	ls_pdir(elem, option, mdir);
	free_list(p);
	free_files(elem);
}

void	ls_file(t_list *p, t_flg option)
{
	t_list		*cd;
	t_dir		*elem;

	cd = p;
	elem = NULL;
	while (cd)
	{
		elem = elemf(elem, cd->data, "");
		cd = cd->next;
	}
	if (elem)
		ls_pfile(elem, option);
	free_files(elem);
	free_list(p);
}

void	ls_path(t_list *p, t_flg option, int mdir)
{
	DIR			*dir;
	t_list		*cd;
	t_list		*f;
	t_list		*d;

	cd = p;
	f = NULL;
	d = NULL;
	while (cd)
	{
		if ((dir = opendir(cd->data)) == NULL)
			(errno == ENOTDIR) ? ft_lstpush(&f, cd->data) : \
			dir_error(cd->data);
		else
		{
			ft_lstpush(&d, cd->data);
			(closedir(dir) == -1) ? cdr_error(cd->data) : NULL;
		}
		cd = cd->next;
	}
	f ? ls_file(f, option) : NULL;
	f && d ? ft_putchar('\n') : NULL;
	d ? ls_dir(d, option, mdir) : NULL;
	free_list(p);
}
