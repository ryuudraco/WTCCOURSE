/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:34:31 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 11:07:14 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*srcd;
	size_t	i;

	i = ft_strlen(src);
	srcd = (char *)ft_memalloc(sizeof(char) * (i + 1));
	if (srcd == NULL)
		return (NULL);
	srcd = (char *)ft_memcpy(srcd, src, i);
	return (srcd);
}
