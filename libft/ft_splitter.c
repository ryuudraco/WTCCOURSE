/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:07:19 by jheath            #+#    #+#             */
/*   Updated: 2018/05/31 16:32:28 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splitter(char **array, const char *s, char c, size_t len)
{
	size_t count;
	size_t wordlength;
	size_t i;

	count = 0;
	i = 0;
	while (count < len)
	{
		wordlength = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			wordlength++;
			i++;
		}
		if ((array[count] = ft_strsub(&s[i - wordlength], 0, wordlength)) == NULL)
			return (0);
		count++;
	}
	array[count] = 0;
	return (1);
}
