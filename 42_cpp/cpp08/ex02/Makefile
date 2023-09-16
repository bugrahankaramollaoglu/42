# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 11:13:51 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/16 11:46:41 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

NAME = MutantStack

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	rm $(OBJ)

fclean :
	rm -rf $(OBJ) $(NAME)

re : fclean $(NAME)
