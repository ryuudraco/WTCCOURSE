/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 10:55:27 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 10:49:14 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*data;
	t_list	*next;

	if (alst && del)
	{
		data = *alst;
		while (data)
		{
			next = data->next;
			del(data->content, data->content_size);
			free(data);
			data = data->next;
		}
		*alst = NULL;
	}
}
