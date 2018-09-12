/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:13:33 by jheath            #+#    #+#             */
/*   Updated: 2018/09/11 16:15:46 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_error(char *file)
{
	ft_putstr("ft_ls: ");
	perror(file);
}

void	cdr_error(char *file)
{
	char *buf;

	buf = (char *)malloc(sizeof(char) * (ft_strlen(file) + 35));
	buf = ft_strjoin(ft_strjoin(NAME, file), ": ");
	ft_putstr(buf);
	ft_putstr(strerror(EINTR));
}