CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC =	Bureaucrat.cpp \
		Form.cpp \
		main.cpp
OBJ =	Bureaucrat.o \
		Form.cpp \
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
