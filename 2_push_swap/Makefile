CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = \
	main.c check.c check2.c stack.c make_node.c make_idx.c push.c swap.c \
	rotate.c reverse_rotate.c sort_tiny.c a_to_b.c b_to_a.c min_command.c last_sort.c
OBJ = \
	main.o check.o check2.o stack.o make_node.o make_idx.o push.o swap.o \
	rotate.o reverse_rotate.o sort_tiny.o a_to_b.o b_to_a.o min_command.o last_sort.o
SRC_BONUS = \
	checker_bonus.c check_bonus.c check2_bonus.c make_node_bonus.c stack_bonus.c push_bonus.c \
	swap_bonus.c rotate_bonus.c reverse_rotate_bonus.c \
	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJ_BONUS = \
	checker_bonus.o check_bonus.o check2_bonus.o make_node_bonus.o stack_bonus.o push_bonus.o \
	swap_bonus.o rotate_bonus.o reverse_rotate_bonus.o \
	./get_next_line/get_next_line.o ./get_next_line/get_next_line_utils.o
MAIN = push_swap
BONUS = checker
BONUS_DIR = get_next_line

.PHONY: all clean fclean re

all: $(MAIN)

$(MAIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJ)

bonus: $(BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_BONUS)
	touch $@

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -I $(BONUS_DIR) -o $(BONUS) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	rm -rf bonus

fclean: clean
	rm -rf $(MAIN)
	rm -rf $(BONUS)

re: fclean all
