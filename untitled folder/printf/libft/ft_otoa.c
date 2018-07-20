/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:40:49 by jheath            #+#    #+#             */
/*   Updated: 2018/07/16 15:45:50 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_otoa(unsigned int n)
{
	unsigned int	i;
	int				size;
	char			*j;

	i = n;
	size = 0;
	while (i > 7)
	{
		i = i / 8;
		size++;
	}
	if (!(j = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	else
	{
		j[size + 1] = '\0';
		while (size >= 0)
		{
			i = n % 8;
			j[size] = 48 + i;
			n = n / 8;
			size--;
		}
	}
	return (j);
}
