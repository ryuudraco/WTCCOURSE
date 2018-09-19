/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:23:53 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:51:56 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_size(t_dir *cd, t_flg option)
{
	int		size;

	size = 0;
	while (cd)
	{
		if (!(option.a == 0 && cd->file[0] == '.'))
			size += cd->blcks;
		cd = cd->next;
	}
	return (size);
}

void		print_space(char *s, int n)
{
	int		i;
	int		v;

	i = ft_strlen(s);
	v = n;
	if (n > 0)
	{
		while (n-- > i)
			write(1, " ", 1);
	}
	write(1, s, i);
	(v > 0) ? ft_strdel(&s) : NULL;
}

void		ls_lfp(t_dir *elem, t_flg option)
{
	print_space(elem->pms, 0);
	ft_putchar(' ');
	print_space(ft_itoa(elem->hlnk), 3);
	ft_putchar(' ');
	(option.g == 1) ? print_space(elem->gid, 0) : print_space(elem->uid, 0);
	ft_putstr("  ");
	(option.g == 0) ? print_space(elem->gid, 0) : NULL;
	ft_putchar(' ');
	print_space(ft_itoa(elem->size), 6);
	ft_putchar(' ');
	print_space(elem->date, 0);
	ft_putchar(' ');
	print_space(elem->file, 0);
	ft_putchar('\n');
}

void		ls_std(t_dir *elem, t_flg option)
{
	t_dir	*cd;

	cd = elem;
	while (cd)
	{
		if (!(option.a == 0 && cd->file[0] == '.'))
		{
			ft_putstr(cd->file);
			ft_putchar('\n');
		}
		cd = cd->next;
	}
}

void		ls_long(t_dir *elem, t_flg option)
{
	t_dir	*cd;

	cd = elem;
	ft_printf("total %d\n", get_size(cd, option));
	while (cd)
	{
		if (!(option.a == 0 && cd->file[0] == '.'))
			ls_lfp(cd, option);
		cd = cd->next;
	}
}
