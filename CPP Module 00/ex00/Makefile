NAME = megaphone

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

all : megaphone.o
	$(CPP) $(CPPFLAGS) megaphone.o -o $(NAME)

clean :
	@rm -f megaphone.o

fclean : clean
	@rm -f $(NAME)

re : fclean all