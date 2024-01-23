CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror
SRC=	AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		main.cpp \
		MateriaSource.cpp
OBJ=	AMateria.o \
		Character.o \
		Cure.o \
		Ice.o \
		main.o \
		MateriaSource.o
MAIN=Materia

.PHONY: all clean fclean re

all : $(MAIN)

 $(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re: fclean all
