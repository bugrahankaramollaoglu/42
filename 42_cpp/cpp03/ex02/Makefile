# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 11:46:57 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/02 18:08:20 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = $(wildcard *.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

