/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:03:22 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:52:07 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <stdio.h>

# define NAME "ft_ls: "
# define ERROR "ls: Invalid option"
# define MSG "\nusage: ./ft_ls [-aglrRt] [file ...]\n"
# define ERROR_DIR ": No such file or directory\n"

typedef struct	s_flg
{
	int				l;
	int				rcr;
	int				a;
	int				r;
	int				t;
	int				g;

}				t_flg;

typedef struct	s_dir
{
	char			*file;
	char			*pms;
	int				hlnk;
	char			*uid;
	char			*gid;
	int				size;
	char			*date;
	time_t			mdate;
	quad_t			blcks;
	char			*dpath;
	struct s_dir	*next;
}				t_dir;

t_dir			*ft_new(char *file, char *p);
void			ls_path(t_list *p, t_flg option, int mdir);
void			ls_pfile(t_dir *elem, t_flg option);
char			*permissions(struct stat s, t_dir *elem);
char			*uid(struct stat s);
char			*gid(struct stat s);
char			*get_time(struct stat s);
void			recursive(t_dir *elem, t_flg option);
t_dir			*sort_lst(t_dir *elem, t_flg option);
void			swap(t_dir *l1, t_dir *l2);
int				elemd(struct dirent *dirp, t_dir **elem, char *p);
t_dir			*elemf(t_dir *elem, char *file, char *p);
void			ls_std(t_dir *elem, t_flg option);
void			ls_long(t_dir *elem, t_flg option);
void			dir_error(char *file);
void			cdr_error(char *file);
void			free_files(t_dir *head);
void			free_list(t_list *head);

#endif
