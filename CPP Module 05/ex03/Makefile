NAME = ex03

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

SRC = main.cpp Bureaucrat.cpp AForm.cpp \
	ShrubberyCreationForm.cpp Intern.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -f $(OBJ) *_shrubbery

fclean : clean
	@rm -f $(NAME)

re : fclean all