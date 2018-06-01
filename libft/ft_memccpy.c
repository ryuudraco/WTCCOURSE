/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:25:27 by jheath            #+#    #+#             */
/*   Updated: 2018/05/25 12:30:26 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *strs;
	char *strd;

	strs = (char *)src;
	strd = (char *)dest;
	while (n > 0 && *strs != c)
	{
		n--;
		*strd++ = *strs++;
	}
	if (n > 0)
	{
		*strd++ = *strs++;
		return ((void *)strd);
	}
	else
		return (NULL);
}
