CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = main.c print_bonus.c setting_bonus.c simulation_bonus.c utils_bonus.c
OBJ = $(SRC:.c=.o)
NAME = philo

.phony: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
