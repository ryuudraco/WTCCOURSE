/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:34:31 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:52:45 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *src)
{
	size_t	n;
	char	*dest;

	n = ft_strlen(src);
	dest = (char*)malloc(sizeof(const char) * (n + 1));
	if (dest)
		ft_memcpy(dest, src, n + 1);
	return (dest);
}
