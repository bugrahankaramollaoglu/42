# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 17:50:26 by bkaramol          #+#    #+#              #
#    Updated: 2023/08/13 18:22:10 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = megaphone

SOURCE = ./megaphone.cpp

all: $(NAME)

$(NAME): $(SOURCE)
	$(CPP) $(CPPFLAGS) $(SOURCE) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

.PHONY: clean all re


