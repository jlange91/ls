# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlange <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 12:33:38 by jlange            #+#    #+#              #
#    Updated: 2017/01/20 17:25:54 by jlange           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all, clean, fclean, re

SRC_PATH = src

OBJ_PATH = obj

LIB_NAME = ft_ls.a

NAME = ft_ls

CC = gcc

HEADER = include/ft_ls.h

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -Iinclude

SRC_NAME =  ft_ls.c					\
			infos.c					\
			recursive.c				\
			rights.c				\
			three.c					\
			tools.c					\
			l_flag.c				\

OBJ = $(SRC_NAME:.c=.o)

OBJ_LIB_NAME = $(addprefix obj/, $(OBJ))

all: $(LIB_NAME)

$(LIB_NAME): obj/ $(HEADER) $(OBJ_LIB_NAME)
	make -C libft
	ar rc $(LIB_NAME) $(OBJ_LIB_NAME)
	ranlib $(LIB_NAME)
	$(CC) $(LIB_NAME) libft/libft.a -o $(NAME)

obj/:
	mkdir $(OBJ_PATH) 2> /dev/null

obj/%.o: src/%.c
	$(CC) -o $@ $(CPPFLAGS) -c $? $(CFLAGS)

clean:
	@make clean -C libft
	rm -rf $(OBJ_PATH)

fclean:
	@make fclean -C libft
	rm -rf $(LIB_NAME) $(OBJ_PATH) $(NAME)

re: fclean all
