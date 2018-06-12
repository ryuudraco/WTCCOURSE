/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:17:49 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 10:54:05 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int val, int fd)
{
	long	n;
	char	str[20];
	int		sign;
	int		i;

	i = 0;
	n = (long)val;
	if ((sign = n) < 0)
		n *= -1;
	str[i++] = (n % 10) + '0';
	n /= 10;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		str[i++] = '-';
	while (i-- > 0)
		write(fd, &str[i], 1);
}
