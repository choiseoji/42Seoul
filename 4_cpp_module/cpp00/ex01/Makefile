CPP = c++
CFLAGS = -Wall -Wextra -Werror
SRC = PhoneBook.cpp Contact.cpp main.cpp
OBJ = PhoneBook.o Contact.o main.o
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
