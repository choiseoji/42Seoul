CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror
SRC=	main.cpp
OBJ=	main.o
MAIN=iter

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re: fclean all
