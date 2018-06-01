/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:56:17 by jheath            #+#    #+#             */
/*   Updated: 2018/06/01 12:30:18 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numwords(char const *s, char b)
{
	size_t wordcount;
	size_t i;

	i = 0;
	wordcount = 0;
	if (s[i] && (s[i] != b) && (s[i + 1] != b) && (s[i + 1] != 0))
		wordcount++;
	while (s[i])
	{
		if ((s[i] == b) && s[i + 1] != b && (s[i + 1] != 0))
		{
			wordcount++;
			i++;
		}
	}
	return (wordcount);
}
