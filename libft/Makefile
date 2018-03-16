# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by nrandria          #+#    #+#              #
#    Updated: 2017/03/10 05:32:42 by jlange           ###   ########.fr        #
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
	  get_next_line.c

OBJ = $(SRC_NAME:.c=.o)

OBJ_NAME = $(addprefix obj/, $(OBJ))

NB_FILES = 69

all: $(NAME)

$(NAME): obj/ $(HEADER) $(OBJ_NAME)
	@rm nb.txt && tput cnorm
	@printf " ✅\n\033[0m"
	@printf "\033[1;36mCreating library\033[0m"
	@ar rc $(NAME) $(OBJ_NAME)
	@printf " ✅\n"
	@printf "\033[1;36mIncrease the search speed\033[0m"
	@ranlib $(NAME)
	@printf " ✅\n\n"

obj/:
	@printf "\n\033[38;5;46m==| LIBFT Makefile |==\033[0m\n"
	@mkdir $(OBJ_PATH) 2> /dev/null
	@touch nb.txt
	@echo 0 > nb.txt
	@echo "\033[1;36mCompiling .o progress : \033[0m"

obj/%.o: src/%.c
	@test=`cat nb.txt`; test=`echo $$test + 1 | bc`; sh loading_bar.sh $(NB_FILES) $$test; echo $$test > nb.txt
	@$(CC) -o $@ $(CPPFLAGS) -c $? $(CFLAGS)

clean:
	@printf "\n\033[1;31mDeleting LIBFT all .o\033[0m\n"
	@rm -rf $(OBJ_PATH)
	@printf "\033[1;32mThe folder is clean ✅\033[0m\n\n"

fclean:
	@printf "\n\033[1;31mDeleting LIBFT Library.a and all .o\033[0m\n"
	@rm -rf $(NAME) $(OBJ_PATH)
	@printf "\033[1;32mThe folder is clean ✅\033[0m\n\n"

re: fclean all
