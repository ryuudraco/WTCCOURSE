/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:43:13 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 11:14:52 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			length;
	char			*trim;

	if (!s)
		return (0);
	i = 0;
	while (IS_WHITESPACE(s[i]))
		i++;
	while (TRIM(s[i]))
		i++;
	length = ft_strlen(s) - 1;
	while (length > i && TRIM(s[length]))
		length--;
	if (length < i)
		return (trim = ft_strdup(""));
	return (trim = ft_strsub(s, i, length - (size_t)i + 1));
}
