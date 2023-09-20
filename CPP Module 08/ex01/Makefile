NAME = ex01

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Span.hpp

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

./%.o: ./%.cpp ./%.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

main.o: main.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all