/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:07:30 by jheath            #+#    #+#             */
/*   Updated: 2018/09/12 17:26:13 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*new;
	void	*d;

	d = (void*)ft_memalloc(ft_strlen((char*)data) + 1);
	if (!d)
		return (NULL);
	if (data == NULL)
		d = NULL;
	else
		d = (void*)ft_strcpy(d, data);
	new = malloc(sizeof(t_list));
	if (new != (t_list*)NULL)
	{
		new->data = d;
		new->next = NULL;
	}
	return (new);
}
