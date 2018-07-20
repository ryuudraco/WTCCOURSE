/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:17:49 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 11:09:00 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*result;
	unsigned int	i;

	if (s && f)
	{
		if (!(str = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		result = str;
		i = 0;
		while (*s)
		{
			*str = f(i, *s);
			str++;
			s++;
			i++;
		}
		*str = '\0';
		return (result);
	}
	return (NULL);
}
