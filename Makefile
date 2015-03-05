# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 19:10:59 by ochase            #+#    #+#              #
#    Updated: 2015/02/24 19:17:33 by bboumend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	ft_ls

SRC_DIR				=	srcs
INCLUDE_DIR			=	includes
OBJ_DIR				=	objs

LIBFT				=	ft
LIBFT_DIR			=	libft
LIBFT_NAME			=	$(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/includes

COMPILER			=	gcc
CFLAGS				=	-g3 -O3 -Wall -Wextra -Werror -c \
						-I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)
LFLAGS				=	-L$(LIBFT_DIR) -l$(LIBFT) -o

SRC					=	main.c           \
						opt_l.c          \
						opt_l2.c         \
						new_info.c       \
						ft_insert.c      \
						comparators.c    \
						parser.c         \
						ft_print.c       \
						ft_ls.c          \
						error.c          \
						display_error.c  \
						display.c        \
						sort_tools.c     \
						print_l.c        \
						padding.c		 \
						recursiv_tools.c \
						padding.c        \
						print_g.c		 \
						parser_tools.c

OBJ					=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all:
	@$(MAKE) $(LIBFT_NAME)
	@$(MAKE) $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(COMPILER) $(LFLAGS) $@ $^

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

test: fclean
	$(MAKE) -C moulitest ft_ls
	./moulitest/ft_ls_tests/ft_ls_test

clean:
	@rm -f $(OBJ)
	@rm -df $(OBJ_DIR)

fcleanlib:
	@(cd $(LIBFT_DIR) && $(MAKE) fclean)

fclean: clean fcleanlib
	@rm -f $(NAME)

re:
	@$(MAKE) fcleanlib
	@$(MAKE) fclean
	@$(MAKE) all
