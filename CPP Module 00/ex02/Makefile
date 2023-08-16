NAME = Accounts

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)

all : $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all