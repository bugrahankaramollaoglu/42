# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 11:31:09 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/14 13:34:55 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

CC = c++

SOURCES = main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS) whatever.hpp
	$(CC) $(OBJECTS) $(CPPFLAGS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
