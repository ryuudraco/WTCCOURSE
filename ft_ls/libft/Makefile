# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheath <jheath@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 12:49:11 by jheath            #+#    #+#              #
#    Updated: 2018/09/11 15:57:48 by jheath           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Source Files
LIBFT =		ft_bzero.c ft_char.c ft_digit.c ft_find_spec.c ft_format.c \
			ft_hex.c ft_isuma.c  ft_itoa.c ft_liter.c ft_lstnew.c \
			ft_lstpush.c ft_memalloc.c ft_memcpy.c ft_memset.c ft_nbr.c \
			ft_nplacesarg.c ft_oct.c ft_point.c ft_printf.c ft_printfputchar.c \
			ft_printfputstr.c ft_putchar.c ft_putendl.c ft_putstr.c ft_putwstr.c \
			ft_str.c  ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c \
			ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strlenpcsn.c \
			ft_strncpy.c ft_strnew.c ft_strsub.c ft_ub.c ft_utoa.c

# Objects
OBJ =       $(LIBFT:.c=.o)

# Flags
FLAGS =     -Wall -Werror -Wextra
HEADER =    -Iincludes

#Colour
G = \033[0;32m
E = \033[0m

.PHONY =    all clean fclean re

all: $(NAME)

# Compilation
$(NAME):	
			@gcc -c $(FLAGS) $(SRC) $(LIBFT) $(HEADER) 
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

# Cleaning up
clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:         fclean all