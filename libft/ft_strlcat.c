/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:54:08 by jheath            #+#    #+#             */
/*   Updated: 2018/06/04 10:06:50 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t srcsize;
	size_t destsize;

	destsize = ft_min(size, ft_strlen((const char*)dest));
	srcsize = ft_strlen(src);
	if (destsize == size)
		return (size + srcsize);
	if (srcsize < size - destsize)
		ft_strncat(dest, src, srcsize + 1);
	else
	{
		ft_strncat(dest, src, size - destsize - 1);
		dest[size - 1] = '\0';
	}
	return ((unsigned int)destsize + (unsigned int)srcsize);
}
