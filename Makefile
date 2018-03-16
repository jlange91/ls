# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlange <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 12:33:38 by jlange            #+#    #+#              #
#    Updated: 2017/03/10 05:41:02 by jlange           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all, clean, fclean, re

SRC_PATH = src

OBJ_PATH = obj

NAME = ft_ls.a

NAME_BIS = ft_ls

CC = gcc

HEADER = include/ft_ls.h

CFLAGS = -g -Wall -Wextra -Werror

CPPFLAGS = -Iinclude

SRC_NAME =  main.c					\
			ft_ls.c					\
			ls_l.c					\
			infos.c					\
			recursive.c				\
			rights.c				\
			rights2.c				\
			fill_three.c			\
			print_three.c			\
			tools.c					\
			tools2.c				\
			tools3.c				\
			tools4.c				\
			l_flag.c				\
			tri_arg.c				\
			print_name.c			\
			colors.c				\
			colors_l.c				\
			color_txt_back.c		\
			color_txt_back_l.c		\
			display_one.c			\
			display_one_l.c			\
			display_one_l2.c		\
			free.c					\
			f_flag.c				\

OBJ = $(SRC_NAME:.c=.o)

OBJ_LIB_NAME = $(addprefix obj/, $(OBJ))

NB_FILES = 25

all: $(NAME)

$(NAME): obj/ $(HEADER) $(OBJ_LIB_NAME)
	@rm nb.txt && tput cnorm
	@printf " ✅\n\033[0m"
	@printf "\033[1;36mCreating library\033[0m"
	@ar rc $(NAME) $(OBJ_LIB_NAME)
	@printf " ✅\n"
	@printf "\033[1;36mIncrease the search speed\033[0m"
	@ranlib $(NAME)
	@printf " ✅\n\n"
	@$(CC) $(NAME) libft/libft.a -o $(NAME_BIS)

obj/:
	@make -C libft
	@printf "\n\033[38;5;46m==| FT_LS Makefile |==\033[0m\n"
	@mkdir $(OBJ_PATH) 2> /dev/null
	@touch nb.txt
	@echo 0 > nb.txt
	@echo "\033[1;36mCompiling .o progress : \033[0m"

obj/%.o: src/%.c
	@test=`cat nb.txt`; test=`echo $$test + 1 | bc`; sh loading_bar.sh $(NB_FILES) $$test; echo $$test > nb.txt
	@$(CC) -o $@ $(CPPFLAGS) -c $? $(CFLAGS)

clean:
	@make clean -C libft
	@printf "\n\033[1;31mDeleting FT_LS all .o\033[0m\n"
	@rm -rf $(OBJ_PATH)
	@printf "\033[1;32mThe folder is clean ✅\033[0m\n\n"

fclean:
	@make fclean -C libft
	@printf "\n\033[1;31mDeleting FT_LS Library.a and all .o\033[0m\n"
	@rm -rf $(NAME) $(OBJ_PATH) $(NAME_BIS)
	@printf "\033[1;32mThe folder is clean ✅\033[0m\n\n"

re: fclean all
