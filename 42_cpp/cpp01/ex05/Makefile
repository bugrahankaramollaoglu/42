# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 21:00:44 by bkaramol          #+#    #+#              #
#    Updated: 2023/08/21 21:00:45 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl

CFLAG = -Wall -Wextra -Werror

OBJ = $(SRC:%.cpp=%.o)

SRC = Harl.cpp main.cpp


all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CFLAG) $(SRC) -o $(NAME) -std=c++98

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
