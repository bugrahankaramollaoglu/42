SRC = main.cpp ScalarConverter.cpp

OBJ	= $(SRC:.cpp=.o)

CXX	= c++

RM	= rm -rf

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++11 # 98 olacak

NAME = convert

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
