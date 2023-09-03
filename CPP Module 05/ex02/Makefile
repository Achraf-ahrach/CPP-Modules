NAME = ex02

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp Bureaucrat.cpp AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME) *_shrubbery

re : fclean all