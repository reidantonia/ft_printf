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
 
NAME = libftprintf.a
 
FLAGS = -Wall -Wextra -Werror
 
LIBFT = libft

SRC_PATH = sources
 
OBJ_PATH = temporary
 
HEADER = includes

SOURCES = 	ft_printf.c \
			main.c		\
 
SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32;7mCompiled ><(((('>"
	
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p temporary
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -s clean -C $(LIBFT)
	@echo "\033[1;33m===> \033[0;31;1m'$(OBJ_PATH)' folder, containing .o's removed \033[1;33m¸,.ø¤º'°'º¤ø.,¸,.ø¤º'°\033[0m"
	@echo "\033[1;33m===> \033[0;31;1m$(LIBFT) cleaned \033[1;33m¸,.ø¤º'°'º¤ø.,¸,.ø¤º'°\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT)
	@echo "\033[1;33m===> \033[0;31;1m$(NAME) removed \033[1;33m¸,.ø¤º'°'º¤ø.,¸,.ø¤'º°\033[0m"

re: fclean all

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(SRC_PATH)/
