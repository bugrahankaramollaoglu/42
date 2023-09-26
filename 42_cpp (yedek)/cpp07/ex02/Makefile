NAME		= Array

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRCS		=	main.cpp	\

OBJS		= $(SRCS:.cpp=.o)

all			: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
