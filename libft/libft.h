/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheath <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:22:48 by jheath            #+#    #+#             */
/*   Updated: 2018/06/01 21:05:05 by jheath           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define TRIM(c) (c == ' ' || c == '\n' || c == '\t')
# define ADDTL_WHITESPACE(c) (c == '\v' || c == '\r' || c == '\f')
# define IS_WHITESPACE(c) (TRIM(c) || ADDTL_WHITESPACE(c))

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_countwords(const char *s, char c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
char		*ft_itoa(int n);
size_t		ft_max(size_t a, size_t b);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *src, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memrchr(const void *s, int c, size_t n);
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_min(size_t a, size_t b);
int			ft_nplacesarg(int num);
size_t		ft_numwords(char const *s, char b);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr(char const *s);
void		ft_putstr_fd(char const *s, int fd);
int			ft_splitter(char **array, const char *s, char c, size_t len);
char		*ft_strcat(char *dest, char *src);
char		*ft_strchr(const char *s, int c);
void		*ft_strclr(char *s);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
char		*ft_strdup(char *src);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strlcat(char *dest, char *src, unsigned int size);
size_t		ft_strlen(const char *s);
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *dest, char *src, int nb);
int			ft_strncmp(const char *dest, const char *s2, size_t n);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(const char *big, const char *little, size_t n);
char		*ft_strrchr(const char *s, int c);
char		**ft_strsplit(char const *s, char c);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_wordlen(const char *s, char c);

#endif
