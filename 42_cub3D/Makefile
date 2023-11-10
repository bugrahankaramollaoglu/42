# Makefile for cub3D

NAME := cub3D
CC := gcc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
SRCS := main.c map_check.c img_utils.c windows_hooks.c color.c ray.c map_utils.c color_utils.c
OBJS := $(SRCS:.c=.o)
RM := rm -f
UNAME := $(shell uname)

LIBFT_DIR := libft

LIBFT := $(LIBFT_DIR)/libft.a

$(NAME): ${OBJS} $(LIBFT)
	@ $(MAKE) -C mlx all >/dev/null 2>&1
	@ cp ./mlx/libmlx.a .
	$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -L$(LIBFT_DIR) -lft -lm -framework OpenGL -framework AppKit

all: ${NAME} cub3d.h

clean:
	@ $(RM) *.o */*.o */*/*.o
	@ rm -rf $(NAME).dSYM >/dev/null 2>&1
	@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	@ $(RM) ${NAME}
	@ rm libmlx.a

re: fclean all

.PHONY: all clean fclean re
