CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC =	Harl.cpp main.cpp
OBJ = 	$(SRC:.cpp=.o)
MAIN = harl

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
