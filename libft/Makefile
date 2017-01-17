# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by nrandria          #+#    #+#              #
#    Updated: 2016/12/08 16:47:47 by jlange           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

SRC_PATH = src

OBJ_PATH = obj

NAME = libft.a

CC = gcc

HEADER = includes/libft.h

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -Iincludes

SRC_NAME = ft_atoi.c		\
	  ft_bzero.c			\
	  ft_isalnum.c			\
	  ft_isalpha.c			\
	  ft_isascii.c			\
	  ft_isdigit.c			\
	  ft_isprint.c			\
	  ft_memalloc.c			\
	  ft_memccpy.c			\
	  ft_memchr.c 			\
	  ft_memcmp.c			\
	  ft_memcpy.c 			\
	  ft_memdel.c			\
	  ft_memmove.c 			\
	  ft_memset.c			\
	  ft_putchar.c			\
	  ft_putchar_fd.c 		\
	  ft_putendl.c			\
	  ft_putendl_fd.c		\
	  ft_putnbr.c 			\
	  ft_putnbr_fd.c		\
	  ft_putstr.c			\
	  ft_putstr_fd.c 		\
	  ft_strcat.c			\
	  ft_strchr.c			\
	  ft_strclr.c 			\
	  ft_strcmp.c			\
	  ft_strcpy.c			\
	  ft_strdel.c			\
	  ft_strdup.c			\
	  ft_strequ.c			\
	  ft_striter.c			\
	  ft_striteri.c			\
	  ft_strjoin.c			\
	  ft_strlcat.c		 	\
	  ft_strlen.c 			\
	  ft_strmap.c			\
	  ft_strmapi.c			\
	  ft_strncat.c			\
	  ft_strncmp.c 			\
	  ft_strncpy.c			\
	  ft_strnequ.c			\
	  ft_strnew.c			\
	  ft_strnstr.c			\
	  ft_strrchr.c			\
	  ft_strstr.c 			\
	  ft_strsub.c			\
	  ft_strtrim.c			\
	  ft_tolower.c			\
	  ft_toupper.c 			\
	  ft_strsplit.c			\
	  ft_itoa.c				\
	  ft_lstnew.c 			\
	  ft_lstdelone.c 		\
	  ft_lstdel.c 			\
	  ft_lstadd.c			\
	  ft_lstiter.c 			\
	  ft_lstmap.c			\
	  ft_push_back.c 		\
	  ft_push_front.c		\
	  ft_create_elem.c 		\
	  ft_intlen.c \
	  ft_uintlen.c \
	  ft_itoa_base.c \
	  ft_itoa_base_maj.c \
	  ft_putwchar.c \
	  ft_putwstr.c \
	  ft_strndup.c \

OBJ = $(SRC_NAME:.c=.o)

OBJ_NAME = $(addprefix obj/, $(OBJ))

all: $(NAME)

$(NAME): obj/ $(HEADER) $(OBJ_NAME)
	@tput cup 3 0 && echo "                                                         "
	@tput cup 1 0 && echo "                                                         "
	@tput cup 1 0
	@ar rc $(NAME) $(OBJ_NAME)
	@echo "\033[36m       Creating library\033[0m\n\033[33m----------------------------------\033[0m"
	@sleep 0.5
	@tput cup 1 0 && echo "                                                         "
	@tput cup 1 0
	@ranlib $(NAME)
	@echo "\033[36m   Increase the search speed\033[0m\n\033[33m----------------------------------\033[0m"
	@sleep 0.5
	@tput cup 1 0 && echo "                                                         "
	@tput cup 1 0
	@echo "\033[32m   ✅  💯  Library Created 💯  ✅\033[0m\n\033[33m----------------------------------\033[0m"

obj/:
	@clear
	@echo "\033[33m----------------------------------\033[0m\n\033[36m        Compiling in .o\033[0m" && mkdir $(OBJ_PATH) 2> /dev/null

obj/%.o: src/%.c
	@$(CC) -o $@ $(CPPFLAGS) -c $? $(CFLAGS)
	@echo "\033[32m✅  Creating $(subst .o,, $@).o\033[0m"
	@echo "\033[33m----------------------------------\033[0m" && tput cup 2 0
	@sleep 0.03
	@tput cup 2 0 && echo "                                                   " && tput cup 2 0

clean:
	@echo "\033[33m----------------------------------\033[0m"
	@echo "\033[31m        Deleting all .o\033[31m"
	@rm -rf $(OBJ_PATH)
	@echo "\033[32m    ✅  The folder is clean ✅\033[32m"
	@echo "\033[33m----------------------------------\033[0m"

fclean:
	@echo "\033[33m----------------------------------\033[0m"
	@echo "\033[31m  Deleting Library.a and all .o\033[31m"
	@rm -rf $(NAME) $(OBJ_PATH)
	@echo "\033[32m    ✅  The folder is clean ✅\033[32m"
	@echo "\033[33m----------------------------------\033[0m"

re: fclean all
