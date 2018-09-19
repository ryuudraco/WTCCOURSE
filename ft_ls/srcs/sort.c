/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:39:27 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:51:59 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		stime(t_dir *l1, t_dir *l2)
{
	if (l1->mdate == l2->mdate)
		return (ft_strcmp(l1->file, l2->file));
	return (l1->mdate < l2->mdate);
}

int		lexographical(t_dir *l1, t_dir *l2)
{
	return (ft_strcmp(l1->file, l2->file));
}

t_dir	*sort(t_dir *elem, int (*cmp)(t_dir *l1, t_dir *l2))
{
	t_dir	*l1;
	t_dir	*l2;

	l1 = elem;
	while (l1)
	{
		l2 = l1->next;
		while (l2)
		{
			if (cmp(l1, l2) > 0)
				swap(l1, l2);
			l2 = l2->next;
		}
		l1 = l1->next;
	}
	return (elem);
}

t_dir	*reverse_sort(t_dir *elem)
{
	t_dir	*a;
	t_dir	*b;
	t_dir	*c;

	a = elem;
	b = NULL;
	c = NULL;
	while (a)
	{
		c = b;
		b = a;
		a = a->next;
		b->next = c;
	}
	elem = b;
	return (elem);
}

t_dir	*sort_lst(t_dir *elem, t_flg option)
{
	t_dir	*r;

	if (!elem)
		return (NULL);
	r = elem;
	r = sort(r, lexographical);
	(option.t == 1) ? r = sort(r, stime) : NULL;
	(option.r == 1) ? r = reverse_sort(r) : NULL;
	return (r);
}
