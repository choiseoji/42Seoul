CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror
SRC=	Span.cpp \
		main.cpp
OBJ=	Span.o \
		main.o
MAIN=span

.PHONY: all clean fclean re

all : $(MAIN)

$(MAIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(MAIN)

re: fclean all
