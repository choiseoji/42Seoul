CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp
OBJ = 	main.o \
		ClapTrap.o \
		ScavTrap.o
MAIN = ClapTrap

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
