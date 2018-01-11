NAME = libftprintf.a

SRC_PATH =  SRCS

SRC_NAME = ft_printf.c

FLAGS = -Wall -Werror -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME)) 

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)


fclean: clean
	/bin/rm -f $(NAME)
