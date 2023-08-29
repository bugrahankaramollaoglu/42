# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 14:19:59 by bkaramol          #+#    #+#              #
#    Updated: 2023/08/20 20:09:58 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJ = $(FILE:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean clean all

