/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:45:09 by jheath            #+#    #+#             */
/*   Updated: 2018/09/12 17:08:26 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_nodes(t_dir *l1, t_dir *l2)
{
	l1->file = l2->file;
	l1->pms = l2->pms;
	l1->hlnk = l2->hlnk;
	l1->uid = l2->uid;
	l1->gid = l2->gid;
	l1->size = l2->size;
	l1->date = l2->date;
	l1->mdate = l2->mdate;
	l1->blcks = l2->blcks;
	l1->dpath = l2->dpath;
}

void	swap(t_dir *l1, t_dir *l2)
{
	t_dir temp;

	temp = *l1;
	swap_nodes(l1, l2);
	swap_nodes(l2, &temp);
}