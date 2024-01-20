CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror
SRC=	Animal.cpp \
		Brain.cpp \
		Cat.cpp \
		Dog.cpp \
		main.cpp
OBJ=	Animal.o \
		Brain.o \
		Cat.o \
		Dog.o \
		main.o
MAIN=AAnimal

.PHONY: all clean fclean re

all : $(MAIN)

 $(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re: fclean all
