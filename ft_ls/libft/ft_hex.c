/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:19:30 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:52:18 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		ft_length(intmax_t n)
{
	size_t i;

	i = 1;
	if (n == 0)
		return (1);
	n /= 16;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static size_t		ft_hexl(t_char *ract, intmax_t n)
{
	int i;
	int j;

	i = ft_length(n);
	j = 0;
	if (ract->pcsn != -1 && ract->pcsn > i)
	{
		j = (ract->pcsn - i);
		i = ract->pcsn;
	}
	if (ract->flg[1] == '#' && n != 0)
		i += 2;
	if (i > 0)
		ract->pcsn = j;
	else if (n == 0 && ract->pcsn == 0)
	{
		ract->pcsn = -2;
		i = 0;
	}
	else
		ract->pcsn = -1;
	return (i);
}

static size_t		ft_printhex(uintmax_t n, t_char *ract, char *base)
{
	int len;

	len = 0;
	if (n == 0 && ract->pcsn == -2)
		return (0);
	if (n >= 16)
	{
		len += ft_printhex(n / 16, ract, base);
		len += ft_printfputchar(base[n % 16]);
	}
	else
		len += ft_printfputchar(base[n % 16]);
	return (len);
}

static int			ft_manager(t_char *ract, uintmax_t n)
{
	int len;

	len = 0;
	if ((ract->flg)[2] == '0' && ract->pcsn == -1)
		(ract->flg)[0] = '0';
	ract->slen = ft_hexl(ract, n);
	if (ract->flg[0] == '0' && ract->flg[1] == '#' && n != 0)
		len += (ract->spec == 'X') ? ft_printfputstr("0X", -1) : \
		ft_printfputstr("0x", -1);
	while ((ract->flg[3] != '-' && ract->width > (ract->slen)))
		(len += ft_printfputchar((ract->flg)[0])) && ract->width--;
	if ((ract->flg)[0] == ' ' && ract->flg[1] == '#' && n != 0)
		len += (ract->spec == 'X') ? ft_printfputstr("0X", -1) : \
		ft_printfputstr("0x", -1);
	while (ract->pcsn != -1 && ract->pcsn > 0)
		(len += ft_printfputchar('0')) && ract->pcsn--;
	len += (ract->spec == 'X') ? ft_printhex(n, ract, "0123456789ABCDEF") : \
	ft_printhex(n, ract, "0123456789abcdef");
	while (ract->width > ract->slen && (ract->flg)[3] == '-')
		(len += ft_printfputchar(' ')) && ract->width--;
	return (len);
}

int					ft_hex(t_char *ract, void *n)
{
	if (ract->h)
		return (ft_manager(ract, (unsigned short)n));
	else if (ract->hh)
		return (ft_manager(ract, (unsigned char)n));
	else if (ract->l)
		return (ft_manager(ract, (unsigned long)n));
	else if (ract->ll)
		return (ft_manager(ract, (unsigned long long)n));
	else if (ract->z)
		return (ft_manager(ract, (size_t)n));
	else if (ract->j)
		return (ft_manager(ract, (uintmax_t)n));
	else
		return (ft_manager(ract, (unsigned int)n));
}
