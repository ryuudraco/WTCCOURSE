/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:34:35 by jheath            #+#    #+#             */
/*   Updated: 2018/09/12 17:36:52 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	next_dir(t_flg option, char *file)
{
	DIR		*dir;
	t_dir	*elem;

	elem = NULL;
	ft_putchar('\n');
	ft_putstr(ft_strjoin(file, ":\n"));
	if ((dir = opendir(file)) != NULL)
	{
		while (elemd(readdir(dir), &elem, ft_strjoin(file, "/")) != 0)
			;
		closedir(dir);
		if (elem)
			ls_pfile(elem, option);
		elem = NULL;
	}
	else
		dir_error(file);
}

void	recursive(t_dir *elem, t_flg option)
{
	t_dir	*cd;

	cd = elem;
	while (cd)
	{
		if (cd->file && cd->dpath && cd->pms[0] == 'd' && \
		ft_strcmp(".", cd->file) && ft_strcmp("..", cd->file) && \
		!(option.a == 0 && cd->file[0] == '.'))
			next_dir(option, cd->dpath);
		cd = cd->next;
	}
}
