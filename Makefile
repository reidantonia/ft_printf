NAME = libftprintf.a

SRCS = ft_printf.c

FLAGS = -Wall -Werror -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
