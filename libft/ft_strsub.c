/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:40:34 by jheath            #+#    #+#             */
/*   Updated: 2018/06/01 10:21:33 by jheath           ###   ########.fr       */
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
