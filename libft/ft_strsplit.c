/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:52:34 by jheath            #+#    #+#             */
/*   Updated: 2018/06/02 17:32:25 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numwords(char const *s, char b)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s[i] && (s[i] != b) && (s[i + 1] != b) && (s[i + 1] != 0))
		count++;
	while (s[i])
	{
		if ((s[i] == b) && (s[i + 1] != b) && (s[i + 1] != 0))
			count++;
		i++;
	}
	return (count);
}

static int	ft_splitter(char **arr, const char *s, char b, size_t len)
{
	size_t count;
	size_t wordlen;
	size_t i;

	count = 0;
	i = 0;
	while (count < len)
	{
		wordlen = 0;
		while (s[i] == b && s[i])
			i++;
		while (s[i] != b && s[i])
		{
			wordlen++;
			i++;
		}
		if ((arr[count] = ft_strsub(&s[i - wordlen], 0, wordlen)) == NULL)
			return (0);
		count++;
	}
	arr[count] = 0;
	return (1);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		len;

	if (!s)
		return (NULL);
	len = ft_numwords(s, c);
	if ((array = ((char **)ft_memalloc(sizeof(char *) * len + 1))) == NULL)
		return (NULL);
	if (ft_splitter(array, s, c, len))
		return (array);
	else
		ft_memdel((void **)array);
	return (array);
}
