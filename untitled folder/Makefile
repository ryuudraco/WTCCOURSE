# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheath <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 16:20:10 by jheath            #+#    #+#              #
#    Updated: 2018/06/26 18:31:49 by jheath           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =						libftprintf.a

CC =						gcc

CFLAGS =					-Wall -Werror -Wextra

LIBFT =						libft

DIR_SRC =					SRC

DIR_OBJ	=					Temp

Header	=					Include

RM =						rm -f

SRC = 

OBJ = 

all =						$(NAME)

$(OBJ) =
					$(CC) $(CFLAGS) -c $(SRC)

$(NAME) =					$(OBJ)
					@ar rc $(NAME) $(OBJ)
					@ranlib $(NAME)

clean =
					@$(RM) $(OBJ)

fclean =					clean
					@$(RM) $(NAME)

re =						fclean all

.PHONY =				all clean fclean clean re
