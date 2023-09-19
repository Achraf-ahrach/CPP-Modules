NAME = ex02

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = MutantStack.hpp

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all