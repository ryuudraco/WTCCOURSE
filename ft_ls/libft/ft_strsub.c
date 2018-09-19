/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:49:56 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:52:50 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s)
		return (NULL);
	new = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	new = (char *)ft_memcpy(new, (s + start), len);
	return (new);
}
