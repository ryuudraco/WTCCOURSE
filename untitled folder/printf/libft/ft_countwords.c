/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:04:21 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 10:46:11 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(const char *s, char c)
{
	int		count;
	int		substring;

	substring = 0;
	count = 0;
	while (*s != '\0')
	{
		if (substring == 1 && *s == c)
			substring = 0;
		else if (substring == 0 && *s != c)
		{
			substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}
