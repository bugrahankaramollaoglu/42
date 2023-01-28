# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 21:30:56 by bkaramol          #+#    #+#              #
#    Updated: 2022/11/14 21:31:04 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
RM = rm -f
CFLAGS	= -Wall -Wextra -Werror
SOURCES = so_long.c game.c parse.c move.c errors_add.c errors_map.c checks.c memory.c
OBJ_FILES = $(SOURCES:.c=.o)
LIB = libft/libft.a

LIBFT = cd libft && make

mlx = ./mlx/libmlx.a

$(NAME) : $(OBJ_FILES)
		$(LIBFT)
		make -C ./mlx
		$(CC) $(CFLAGS) -o so_long $(OBJ_FILES) $(LIB) $(mlx) -Lmlx -lmlx -framework OpenGL -framework AppKit 

%.o : %.c
	$(CC) -c $(CFLAGS) -Imlx $<

clean:
	$(RM) $(OBJ_FILES)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

all: $(NAME)

re: fclean all

.PHONY:	all clean fclean re