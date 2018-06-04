/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:25:27 by jheath            #+#    #+#             */
/*   Updated: 2018/06/04 10:43:26 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*strd;
	const unsigned char	*strs;
	size_t				i;

	strd = (unsigned char *)dest;
	strs = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		strd[i] = strs[i];
		if (strs[i] == (unsigned char)c)
			return ((void *)(strd + i + 1));
		i++;
	}
	return (NULL);
}
