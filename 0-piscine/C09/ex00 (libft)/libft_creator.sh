# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 09:38:03 by bkaramol          #+#    #+#              #
#    Updated: 2023/01/28 09:38:59 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

gcc -Wall -Werror -Wextra -c ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
ar rcs libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
rm ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
ranlib libft.a
