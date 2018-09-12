/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:08:49 by jheath            #+#    #+#             */
/*   Updated: 2018/09/11 14:09:05 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **lst, void *data)
{
	t_list	*list;

	list = *lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(data);
	}
	else
	{
		*lst = ft_lstnew(data);
	}
}