/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:58:44 by jheath            #+#    #+#             */
/*   Updated: 2018/06/19 11:51:34 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		searchline(char *buf)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

int	get_line(const int fd, char *buf, char *strs[fd])
{
	int		r;
	char	*temp;

	while ((searchline(buf) != 1) && ((r = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[r] = '\0';
		temp = strs[fd];
		strs[fd] = ft_strjoin(temp, buf);
		ft_strdel(&temp);
	}
	ft_strdel(&buf);
	if (r < 0)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*strs[2147483647];
	char		*buf;
	char		*str;
	char		*temp;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	if (!strs[fd])
		strs[fd] = ft_strnew(0);
	if ((ret = get_line(fd, buf, strs)) == -1)
		return (-1);
	if ((str = ft_strchr(strs[fd], '\n')))
	{
		*line = ft_strsub(strs[fd], 0, str - strs[fd]);
		temp = strs[fd];
		strs[fd] = ft_strdup(str + 1);
		ft_strdel(&temp);
		return (1);
	}
	*line = ft_strdup(strs[fd]);
	ft_strdel(&strs[fd]);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
