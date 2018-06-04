/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:07:30 by jheath            #+#    #+#             */
/*   Updated: 2018/06/03 11:28:17 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *data;
	t_list *next;

	if (lst && f)
	{
		data = lst;
		while (data->next)
		{
			next = data->next;
			f(data);
			data = next;
		}
		f(data);
	}
}
