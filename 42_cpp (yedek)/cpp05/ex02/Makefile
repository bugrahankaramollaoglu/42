# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 18:33:20 by bkaramol          #+#    #+#              #
#    Updated: 2023/09/10 12:45:56 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@c++ -o $(NAME) $(CPPFLAGS) $(OBJ)

clean:
	@rm -rf $(OBJ)
	@ rm -rf home_shrubbery

fclean: clean
	@rm -f $(NAME)

re: fclean all
