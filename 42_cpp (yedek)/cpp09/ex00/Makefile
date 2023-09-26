# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 11:54:52 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/16 11:54:53 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CXXFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = c++

STD = -std=c++98

SRC = BitcoinExchange.cpp main.cpp

INC = BitcoinExchange.hpp

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
