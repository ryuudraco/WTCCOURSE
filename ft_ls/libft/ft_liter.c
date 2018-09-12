/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 22:35:21 by jheath            #+#    #+#             */
/*   Updated: 2018/09/12 16:53:26 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_liter(t_char *ract, char c)
{
	int len;

	len = 0;
	if ((ract->flg)[2] == '0')
		(ract->flg)[0] = '0';
	if ((ract->flg)[3] != '-' && ract->width > 1)
	{
		while (((ract->width)-- - 1))
			len += ft_printfputchar((ract->flg)[0]);
	}
	len += ft_printfputchar(c);
	if (ract->width > 1 && (ract->flg)[3] == '-')
	{
		while ((ract->width)-- - 1)
			len += ft_printfputchar(' ');
	}
	return (len);
}
