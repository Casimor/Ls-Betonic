#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/23 13:01:06 by bchevali          #+#    #+#              #
#    Updated: 2014/10/01 14:24:57 by bchevali         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

INC = ./includes

SRC = ./srcs/main.c ./srcs/ft_ls.c ./srcs/ft_print.c ./srcs/ft_flag.c \
	./srcs/ft_tools.c

OBJ = main.o ft_ls.o ft_print.o ft_flag.o ft_tools.o

FLAGS = -Wall -Wextra -Werror -I$(INC)

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ)

%.o: $(SRC_DIR)/%.c
	gcc -c $(FLAGS) $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re