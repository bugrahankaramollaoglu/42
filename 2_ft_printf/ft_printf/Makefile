SRC = tools0.c tools1.c tools2.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

NAME = libftprintf.a

all: $(NAME) $(GCC)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
