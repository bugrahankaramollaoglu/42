NAME = libft.a
CC = gcc
RM = rm -f
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -cq
C_FILES = ft_memcpy.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c get_next_line.c get_next_line_utils.c ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_point.c ft_print_string.c ft_print_unsigned_int.c  
O_FILES = $(C_FILES:.c=.o)

$(NAME) : $(O_FILES) libft.h
	$(AR) libft.a $(O_FILES)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean: 
	$(RM) $(O_FILES) $(O_FILES_BONUS)

fclean: clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re		
