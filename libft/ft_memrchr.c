/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:48:14 by jheath            #+#    #+#             */
/*   Updated: 2018/06/01 12:03:53 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char 	*str;
	size_t		i;

	str = (unsigned char *)s;
	i = (n - 1);
	while (i > 0)
	{
		if (buffer[i] == (unsigned char )c)
			return (str + i);
		i--;
	}
	if (str[0] == (unsigned char )c)
		return ((void *)str);
	return (NULL);
}
