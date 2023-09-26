# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 00:07:01 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/16 00:07:25 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CC = c++

SOURCES = main.cpp Span.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJECTS) Span.hpp
	$(CC) $(OBJECTS) $(CPPFLAGS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
