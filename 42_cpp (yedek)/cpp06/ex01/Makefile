# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 21:02:35 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/12 21:02:35 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = c++ 

STD = -std=c++98

SRC = Serializer.cpp main.cpp

INC = Serializer.hpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CXXFLAGS) $(STD) $(OBJ) -o $(NAME)

%.o : %.cpp $(INC)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
