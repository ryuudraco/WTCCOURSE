# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheath <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 16:20:10 by jheath            #+#    #+#              #
#    Updated: 2018/07/16 13:32:38 by jheath           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =						libftprintf.a

# Flags.
CC =						gcc
CFLAGS =					-Wall -Werror -Wextra
HEADER =					-Includes

# Remove.
RM =						rm -f

# SubFolders
DIR_LIBFT =					libft/
DIR_SRC =					SRC/

# Source Files.
LIBFTS =					ft_hidenp.c ft_htoa.c ft_itoa.c ft_len.c \
							ft_neg.c ft_putchar.c ft_putnbr.c ft_putstr.c \
							ft_otoa.c ft_strdup.c ft_strlen.c ft_toupper.c

SRCS =						ft_char.c ft_find_spec.c ft_hex.c ft_hex_U.c \
							ft_printf.c ft_nbr.c ft_oct.c ft_str.c

# File Paths.
LIBFT =						$(addprefix $(DIR_LIBFT),$(LIBFTS))
SRC =						$(addprefix $(DIR_SRC),$(SRCS))

all =						$(NAME)

# Compilation
$(NAME):
						@$(CC) -c $(CFLAGS) $(SRC) $(LIBFT) $(HEADER)
						@ar rc $(NAME) $(OBJ)
						@ranlib $(NAME)
						@echo "Structure complete!"

# Cleanup duty
clean :
						@$(RM) $(OBJ)

fclean :					clean
						@$(RM) $(NAME)

re :						fclean all

.PHONY =					all clean fclean clean re
