/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:46:54 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:52:46 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	length;
	char	*combined;

	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	combined = ft_strnew(length);
	if (combined == NULL)
		return (NULL);
	ft_strcat(combined, (char *)s1);
	ft_strcat(combined, (char *)s2);
	return (combined);
}
