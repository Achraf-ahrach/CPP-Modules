NAME = ex00

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

all : $(NAME)

$(NAME) : main.o
	$(CXX) $(CPPFLAGS) main.o -o $(NAME)

main.o: main.cpp easyfind.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	@rm -f main.o

fclean : clean
	@rm -f $(NAME)

re : fclean all