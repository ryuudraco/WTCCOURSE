/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <jheath@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:22:48 by jheath            #+#    #+#             */
/*   Updated: 2018/09/19 12:52:05 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
** --------------------------------------------------------------------------|*
** 									LIBFT 									 **
** --------------------------------------------------------------------------|*
*/

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
int					ft_digit(int c);
int					ft_isuma(char **s);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void	*data);
void				ft_lstpush(t_list **lst, void *data);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_nplacesarg(int num);
int					ft_printfputchar(int c);
int					ft_printfputstr(char const *s, int pcsn);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putstr(const char *s);
int					ft_putwstr(wchar_t *wides, int pcsn);
char				*ft_strcat(char *dest, const char *src);
int					ft_strchr(char *str, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
char				*ft_strjoin(const char *s1, const char *s2);
int					ft_strlen(const char *s);
int					ft_strlenpcsn(const char *s, int pcsn);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_utoa(unsigned int n);

/*
** |--------------------------------------------------------------------------|*
** 									PRINTF									  **
** |--------------------------------------------------------------------------|*
*/

# define ABS(n) ((n < 0) ? -n : n)
# define IND			"+-#0 .123456789hljz"
# define SPECS			"%sSpdDioOuUxXcC"
# define FLAGS			"#0-+ "
# define CFLAGS			"hljz"

typedef struct		s_char
{
	char	*flg;
	short	width;
	short	pcsn;
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		z;
	int		j;
	char	spec;
	short	slen;
}					t_char;

int					ft_char(t_char *ract, void *c);
int					ft_find_spec(t_char *ract, va_list arg);
int					ft_format(char **form, va_list arg);
int					ft_hex(t_char *ract, void *n);
int					ft_liter(t_char *ract, char c);
int					ft_nbr(t_char *ract, void *n);
int					ft_oct(t_char *ract, void *n);
int					ft_point(t_char *ract, void *n);
int					ft_printf(const char *format, ...);
int					ft_str(t_char *ract, void *s);
int					ft_ub(t_char *ract, void *n);

#endif
