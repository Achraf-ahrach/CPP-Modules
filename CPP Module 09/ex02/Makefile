NAME = PmergeMe

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

PmergeMe.o: PmergeMe.cpp PmergeMe.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

main.o: main.cpp PmergeMe.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all