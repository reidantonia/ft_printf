# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areid <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 10:38:16 by areid             #+#    #+#              #
#    Updated: 2018/02/12 09:46:14 by areid            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = a.out
NAME = libftprintf.a

SRC_PATH = sources

SRC_NAME = ft_printf.c

HEADER = includes

OBJ_PATH = sources

CFLAGS = -Wall -Werror -Wextra

CC = gcc

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : $(NAME)

$(NAME): $(OBJ)
	@(make -s -C libft/ fclean && make -s -C libft/)
#@(cp libft/libft.a ./$(NAME))
	@(ar rc $(NAME) $(OBJ))
	@(ranlib $(NAME))

#$(OBJ_PATH)%.o): $(SRC_PATH)%.c
#@(mkdir $(OBJ_PATH) 2> /dev/null)
#@(gcc $(CFLAGS) -I $(HEADER) -o $@ -c $<)

clean:
	@(rm -fv $(OBJ))
	@(rmdir $(OBJ_PATH) 2> /dev/null || true)
	@(make -s -C libft/ clean)

fclean: clean
	@(rm -fv $(NAME))
	@(make -s -C libft/ fclean)

re : fclean all
	@(make -s -C libft/ re)

#.PHONY : all, fclean, clean, re

norme :
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h
