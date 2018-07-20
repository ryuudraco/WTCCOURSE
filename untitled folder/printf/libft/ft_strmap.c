/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:11:34 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 11:08:44 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	length;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	str = ft_strnew(length);
	if (str == NULL)
		return (NULL);
	while (i < length)
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
