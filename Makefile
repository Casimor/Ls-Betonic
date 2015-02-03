#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochase <ochase@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 19:10:59 by ochase            #+#    #+#              #
#    Updated: 2013/12/15 14:20:38 by ochase           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

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
<<<<<<< HEAD
						padding.c		 \
						recursiv_tools.c
=======
						padding.c        \
						print_g.c
>>>>>>> b68358d31c0be10bce723c32954bbb2e80ff8e0f

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
