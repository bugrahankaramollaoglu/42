# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 21:00:44 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/02 13:55:03 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Harl.cpp main.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
