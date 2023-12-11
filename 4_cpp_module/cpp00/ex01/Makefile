CPP = c++
CFLAGS = -Wall -Wextra -Werror
SRC = phone_book.cpp
OBJ = phone_book.o
MAIN = phonebook

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CPP) $(CFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re : fclean all
