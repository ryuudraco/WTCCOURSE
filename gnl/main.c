/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:22:39 by jheath            #+#    #+#             */
/*   Updated: 2018/06/12 11:39:17 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char	*line;
	
	fd = open("asd.txt", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
