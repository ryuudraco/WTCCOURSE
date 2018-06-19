/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:22:39 by jheath            #+#    #+#             */
/*   Updated: 2018/06/18 13:23:51 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int ret;
	int	fd;
	char	*line;
	
	fd = open("asd.txt", O_RDONLY);
	while((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d %s\n", ret, line);
	}
	close(fd);
	return (0);
}
