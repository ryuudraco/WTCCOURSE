/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:20:49 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 10:51:08 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *strs;

	strs = (unsigned char *)src;
	while (n > 0 && *strs != (unsigned char)c)
	{
		n--;
		strs++;
	}
	if (n == 0)
		return (NULL);
	else
		return (strs);
}
