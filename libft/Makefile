#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochase <ochase@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:35:04 by ochase            #+#    #+#              #
#    Updated: 2014/03/18 06:19:52 by ochase           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a

SRC_DIR		=	srcs
INCLUDE_DIR	=	includes

SRC			=	ft_isalpha.c           \
				ft_memmove.c           \
				ft_putstr.c            \
				ft_strstr.c            \
				ft_isascii.c           \
				ft_memset.c            \
				ft_putstr_fd.c         \
				ft_tolower.c           \
				ft_isdigit.c           \
				ft_putchar.c           \
				ft_strcat.c            \
				ft_strlen.c            \
				ft_toupper.c           \
				ft_isprint.c           \
				ft_putchar_fd.c        \
				ft_strchr.c            \
				ft_strncat.c           \
				ft_strlcat.c           \
				ft_memccpy.c           \
				ft_putendl.c           \
				ft_strclr.c            \
				ft_strncmp.c           \
				ft_atoi.c              \
				ft_memchr.c            \
				ft_putendl_fd.c        \
				ft_strcmp.c            \
				ft_strncpy.c           \
				ft_bzero.c             \
				ft_memcmp.c            \
				ft_putnbr.c            \
				ft_strcpy.c            \
				ft_strnstr.c           \
				ft_isalnum.c           \
				ft_memcpy.c            \
				ft_putnbr_fd.c         \
				ft_strdup.c            \
				ft_strrchr.c           \
				ft_striteri.c          \
				ft_striter.c           \
				ft_memalloc.c          \
				ft_memdel.c            \
				ft_strnew.c            \
				ft_strdel.c            \
				ft_strmap.c            \
				ft_strmapi.c           \
				ft_itoa.c              \
				ft_strequ.c            \
				ft_strnequ.c           \
				ft_strsub.c            \
				ft_strjoin.c           \
				ft_strtrim.c           \
				ft_strsplit.c          \
				ft_lstdel.c            \
				ft_lstdelone.c         \
				ft_lstiter.c           \
				ft_lstadd.c            \
				ft_lstnew.c            \
				ft_setcolor.c          \
				ft_resetcolor.c        \
				ft_lstpushback.c       \
				ft_lstrev.c            \
				ft_lstsize.c           \
				ft_str_split.c         \
				ft_utoa.c              \
				ft_itoa_base.c         \
				ft_lstd_add.c          \
				ft_lstd_new.c          \
				ft_lstd_pushback.c     \
				ft_lstd_foreach.c      \
				ft_lstd_size.c         \
				ft_lstd_delone.c       \
				ft_get_maxsize.c       \
				ft_lst_foreach.c       \
				ft_free_lst.c          \
				ft_free_tab.c          \
				ft_tab_foreach.c       \
				ft_insert_tree.c       \
				ft_new_tree.c          \
				ft_delet_tree.c        \
				ft_delone_tree.c       \
				ft_tree_find.c         \
				ft_tree_remove.c       \
				ft_tablen.c            \
				ft_strunion.c          \
				ft_free_lstd.c         \
				ft_lstdnc_pushback.c   \
				ft_free_lstdnc.c       \
				ft_lstdnc_size.c       \
				ft_lstdnc_del_last.c   \
				ft_lstdnc_del_cur.c    \
				ft_lstmap.c            \
				ft_ignore_whitespace.c \
				ft_split_tools.c       \
				ft_map_insert.c        \
				ft_map_foreach.c       \
				ft_map_get.c           \
				ft_map_remove.c        \
				ft_map_delete.c        \
				ft_djb2.c

OBJ_DIR		=	objs
OBJ			=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

COMPILER	=	gcc
CFLAGS		=	-O3 -Wall -Wextra -Werror -I$(INCLUDE_DIR) -c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)
	rm -df $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
