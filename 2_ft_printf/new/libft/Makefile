# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 23:16:20 by bkaramol          #+#    #+#              #
#    Updated: 2023/02/03 03:40:22 by bkaramol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \

BONUSES	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		  ft_lstdelone.c ft_lstiteri.c ft_lstlast.c \
		  ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJECTS = ${SOURCES:.c=.o}

BONUS_OBJECTS = ${BONUSES:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJECTS} ${BONUS_OBJECTS}
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

clean:
	@rm -rf ${OBJECTS} ${BONUS_OBJECTS}
	@echo "[clean] has been used."
fclean: clean
	@rm -rf ${NAME}
	@echo "[fclean] has been used."

re: fclean all
	@echo "[re] has been used."

bonus: ${OBJECTS} ${BONUS_OBJECTS}
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
