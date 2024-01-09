CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC =	main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp
OBJ = 	main.o \
		Fixed.o \
		Point.o \
		bsp.o
MAIN = BSP

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
