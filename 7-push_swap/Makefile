# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 18:45:11 by bkaramol          #+#    #+#              #
#    Updated: 2023/01/14 16:11:21 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = tools0.c tools1.c tools2.c tools3.c tools4.c tools5.c tools6.c tools7.c tools8.c tools9.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
NAME = push_swap
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY = all clean fclean re
