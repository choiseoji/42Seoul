CPP = c++
CFLAGS = -Wall -Wextra -Werror
SRC = Account.cpp tests.cpp
OBJ = Account.o tests.o
MAIN = Account

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CPP) $(CFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
