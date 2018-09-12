/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:22:58 by jheath            #+#    #+#             */
/*   Updated: 2018/09/12 17:07:22 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check(char c)
{
	ft_printf("%s%c%s", ERROR, c, MSG);
	exit(0);
}

t_flg	*get_options(char *s[], t_flg *option)
{
	int 	i;

	while (*++s)
	{
		i = 0;
		if (*s[0] != '-')
			break ;
		while (*++s[i])
		{
			if (ft_strchr("lRartg", *s[i]))
			{
				option->l = (**s == 'l' ? 1 : option->l);
				option->rcr = (**s == 'R' ? 1 : option->rcr);
				option->a = (**s == 'a' ? 1 : option->a);
				option->r = (**s == 'r' ? 1 : option->r);
				option->t = (**s == 't' ? 1 : option->t);
				option->g = (**s == 'g' ? 1 : option->g); 
			}
			else
			{
				check(*s[i]);
			}
		}
	}
	return (option);
}

void	ls_handle(t_list **p, t_flg *option, char *av[])
{
	int		i;

	i = 0;
	option = get_options(av, option);
	while (av[++i])
	{
		if (!av[i][0])
			continue ;
		if (p)
			ft_lstpush(p, av[i]);
	}
}

int		main(int argc, char **argv)
{
	t_flg	option;
	t_list	*p;

	ft_bzero(&option, sizeof(option));
	p = NULL;
	if (argc > 1)
		ls_handle(&p, &option, argv);
	if (p == NULL)
		ft_lstpush(&p, ".");
	ls_path(p, option, p->next != NULL ? 1 : 0);
	return (0);
}