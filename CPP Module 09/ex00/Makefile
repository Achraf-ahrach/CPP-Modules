NAME = btc

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

./%.o: ./%.cpp ./%.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

main.o: main.cpp BitcoinExchange.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all