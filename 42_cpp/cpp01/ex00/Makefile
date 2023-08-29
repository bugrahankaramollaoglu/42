# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 11:04:39 by bkaramol          #+#    #+#              #
#    Updated: 2023/08/20 11:07:30 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp randomChump.cpp newZombie.cpp Zombie.cpp

OBJ = $(SOURCES:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CPPFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean clean all

