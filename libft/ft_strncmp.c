/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:29:22 by jheath            #+#    #+#             */
/*   Updated: 2018/05/31 12:37:44 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (ft_min(ft_strlen(s1), ft_strlen(s2)) <n)
		n = ft_min(ft_strlen(s1), ft_strlen(s2)) + 1;
	if (n == 0)
		return (0)
	return (ft_memcmp(s1, s2, n));
}
