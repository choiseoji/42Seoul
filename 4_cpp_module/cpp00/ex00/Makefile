CPP = c++
CFLAGS = -Wall -Wextra -Werror
SRC = megaphone.cpp
OBJ = megaphone.o
MAIN = megaphone

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CPP) $(CFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
