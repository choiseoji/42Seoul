CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp
OBJ = 	main.o \
		Zombie.o \
		newZombie.o \
		randomChump.o
MAIN = Zombie

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
