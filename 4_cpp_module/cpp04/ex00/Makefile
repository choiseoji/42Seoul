CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror
SRC=	Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		main.cpp
OBJ=	Animal.o \
		Cat.o \
		Dog.o \
		WrongAnimal.o \
		WrongCat.o \
		main.o
MAIN=Animal

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re: fclean all
