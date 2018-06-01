/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:52:34 by jheath            #+#    #+#             */
/*   Updated: 2018/05/31 16:36:55 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const s, char c)
{
	char	*array;
	int	len;

	if (!s)
		return (NULL);
	len = ft_numwords(s, c);
	else if ((array = ((char **)ft_memalloc(sizeof(char *) * len + 1))) == NULL)
		return (NULL);
	else if (ft_splitter(array, s, c, len))
		return (array);
	else
		ft_memdel((void **)array);
	return (array);
}
