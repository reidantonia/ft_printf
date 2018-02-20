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

CPPFLAGS = -Iincludes

OBJ_PATH = sources

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LDFLAGS = -Llibft

LDLIBS = -lft

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : $(NAME)

$(NAME): $(OBJ)
	@(make -C libft/ fclean && make -C libft/)
	@($(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@(@mkdir $(OBJ_PATH) 2> /dev/null)
	$(CC) $< $(CFLAGS)
	#@$(CC) $(CFLAGS) -o $@ $< $(CPPFLAGS)

clean:
	@(rm -fv $(OBJ))
	@(@rmdir $(OBJ_PATH) 2> /dev/null || true)
	@(make -C libft/ clean)

fclean: clean
	@(rm -fv $(NAME))
	@(make -C libft/ fclean)

re : fclean all
	@(make -C libft/ re)

.PHONY : all, fclean, clean, re

norme :
	norminette $(SRC)
	norminette $(INC_PATH)*.h
