CC = cc
CFLAGS = -Wall -Wextra -Werror 
# -g -fsanitize=thread
SRC = main.c monitoring.c print.c setting.c simulation.c utils.c
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
