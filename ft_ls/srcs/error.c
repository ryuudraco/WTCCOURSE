/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:13:33 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:51:51 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_files(t_dir *head)
{
	t_dir *tmp;

	tmp = NULL;
	tmp = head->next;
	(head->dpath) ? free(head->dpath) : NULL;
	(head->pms) ? free(head->pms) : NULL;
	(head->date) ? free(head->date) : NULL;
	head = tmp;
}

void free_list(t_list *head)
{
	t_list *cur = NULL;

	while ((cur = head) != NULL)
    {
        head = head->next;
        free(cur->data);
		free(cur);
    }
}

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
	ft_strdel(&buf);
	ft_putstr(strerror(EINTR));
}
