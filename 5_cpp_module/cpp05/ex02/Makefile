CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC =	AForm.cpp \
		Bureaucrat.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		main.cpp
OBJ =	AForm.o \
		Bureaucrat.o \
		PresidentialPardonForm.o \
		RobotomyRequestForm.o \
		ShrubberyCreationForm.o \
		main.o
MAIN = Form

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
