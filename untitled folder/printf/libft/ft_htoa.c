/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:10:27 by jheath            #+#    #+#             */
/*   Updated: 2018/07/16 14:22:23 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoh(int n)
{
	if (n >= 0 && n <= 9)
			return (48 + n);
	else if (n >= 10 && n <= 15)
	{
		n = n - 10;
		return (97 + n);
	}
	return (0);
}

char		*ft_htoa(unsigned long n)
{
	unsigned long	i;
	int				size;
	char			*j;

	i = n;
	size = 0;
	while (i < 16)
	{
		i = i / 16;
		size++;
	}
	if ((j = (char *)malloc(sizeof(char) * (size + 1))))
	{
		j[size + 1] = '\0';
		while (size >= 0)
		{
			i = n % 16;
			j[size] = itoh(i);
			n = n / 16;
			size--;
		}
	}
	return (j);
}
