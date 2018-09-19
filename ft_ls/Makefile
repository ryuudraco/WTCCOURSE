# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheath <jheath@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 13:00:51 by jheath            #+#    #+#              #
#    Updated: 2018/09/19 12:52:58 by jheath           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME =      ft_ls 

# Directories
DIR_LIB =   libft/
DIR_SRC =   srcs/
DIR_OBJ =   obj/
    
# Source Files
SRCS =      elements.c error.c ft_ls.c get_elements.c main.c \
			print.c recursion.c sort.c swap.c

# Source Paths
SRC =       $(addprefix $(DIR_SRC), $(SRCS))

# Object Files
OBJS = $(SRCS:.c=.o)

# Object Paths
OBJ = $(addprefix $(DIR_OBJ), $(OBJS))

# Flags
FLAGS =     -Wall -Werror -Wextra -g
HEADER =       -Iincludes/ -Ilibft/includes/

# Colour
R = \033[0;31m
P = \033[0;35m
E = \033[0m

all:		$(NAME)

# compilation
$(NAME):	$(OBJ) 
		@make -C libft/
		@gcc $(FLAG) $(OBJ) $(HEADER) -L $(DIR_LIB) -lft -o $(NAME)
		@echo "$(P)Warp in complete$(E)"

$(DIR_OBJ)%.o:	$(DIR_SRC)%.c
		@mkdir -p obj
		@gcc $(FLAGS) $(HEADER) -o $@ -c $<

# Cleaning up
clean:
		@make -C $(DIR_LIB) clean
		@rm -rf $(DIR_OBJ)
		@echo "$(R)Mineral field depleted!$(E)"

fclean:		clean
		@make -C $(DIR_LIB) fclean
		@rm -rf $(NAME)
		@echo "$(R)Nuclear Launch Detected!$(E)"

re:     fclean all

.PHONY: all clean fclean re
