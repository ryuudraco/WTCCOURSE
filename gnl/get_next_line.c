/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:58:44 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 11:35:15 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_malloc(char **s)
{
	char	*temp;

	if (!(temp = ft_strnew(ft_strlen(*s))))
		return (0);
	ft_strcpy(temp, *s);
	*s = NULL;
	if (!(*s = ft_strnew(ft_strlen(temp) + BUFF_SIZE)))
		return (0);
	else
		return (1);
	
}

int		ft_line(char **s, char **line, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (n != 0 || ft_strlen(*s) != 0)
	{
		while(*s[i] != '\n')
		{
			*line[i] = *s[i];
			i++;
		}
		*line[i++] = '\0';
		if (*s[0] == '\n')
		{
			while (*s[i])
				*s[j++] = *s[i++];
			*s[j] = '\0';
			return (-1);
		}
		while (*s[i])
			*s[j++] = *s[i++];
		*s[j] = '\0';
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int		i;
	static char	*s;

	if (fd < 0 || (!s && !(s = ft_strnew(BUFF_SIZE))))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while ((i = read(fd, *line, BUFF_SIZE)) > 0)
	{
		if (!(ft_malloc(&s)))
			return (-1);
		ft_strncat(s, *line, BUFF_SIZE);
		if (ft_memchr(*line, '\n', BUFF_SIZE))
			break ;
	}
	if  ((ft_line(&(*line), &s, i)) == 2)
		return (1);
	if (ft_memcmp((*line), s, ft_strlen(*line)) == 0)
	{
		if (!(*line = ft_strdup("")))
			return (1);
		return (0);
	}
	return (1);
}
