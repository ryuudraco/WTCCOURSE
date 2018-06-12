/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:44:43 by jheath            #+#    #+#             */
/*   Updated: 2018/06/08 14:34:17 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t check;
	size_t length;
	size_t i;

	check = ft_min(ft_strlen(big) + 1, n);
	length = ft_strlen(little);
	i = 0;
	if (!(unsigned char)little[0])
		return (char *)(big);
	while (i < check && length <= (n - i))
	{
		if (ft_strncmp((big + i), little, length) == 0)
			return (char *)(big + i);
		i++;
	}
	return (NULL);
}
