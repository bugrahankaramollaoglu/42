# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 13:52:26 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/04 13:52:28 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)

OBJECTS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: clean all
