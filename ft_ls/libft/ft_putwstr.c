/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:14:16 by jheath            #+#    #+#             */
/*   Updated: 2018/09/12 16:46:59 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_wideclen(unsigned int widec)
{
	if (widec <= 127)
		return (1);
	else if (widec <= 2047)
		return (2);
	else if (widec <= 65535)
		return (3);
	else if (widec <= 2097151)
		return (4);
	else
		return (0);
}

static int	ft_putwidechar(wchar_t widec)
{
	int				len;
	int				slen;
	unsigned int	current;

	len = 0;
	slen = ft_wideclen(widec);
	if (slen == 1)
		return (ft_printfputchar(widec));
	current = (240 << (4 - slen)) | (widec >> ((slen - 1) * 6));
	len += ft_printfputchar(current);
	slen--;
	while (slen)
	{
		current = ((widec >> ((slen) * 6)) & 63) | 128;
		len += ft_printfputchar(current);
	}
	return (len);
}

int			ft_putwstr(wchar_t *wides, int pcsn)
{
	int		len;

	len = 0;
	if (wides == NULL)
		return (ft_printfputstr("(null)", pcsn));
	while (*wides)
	{
		len += ft_putwidechar(*wides);
		wides++;
	}
	return (len);
}
