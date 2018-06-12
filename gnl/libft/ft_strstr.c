/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:37:19 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 11:14:18 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t length;

	i = 0;
	length = ft_strlen(big);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < length)
	{
		if (ft_memcmp((big + i), little, ft_strlen(little)) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
