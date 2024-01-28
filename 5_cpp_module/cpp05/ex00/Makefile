CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC =	Bureaucrat.cpp \
		main.cpp
OBJ =	Bureaucrat.o \
		main.o
MAIN = Bureaucrat

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
