CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c error.c do_cmd.c
OBJ = main.o error.o do_cmd.o
SRC_B = main_bonus.c error_bonus.c envp_access_bonus.c fd_close_bonus.c is_here_doc_bonus.c pipe_bonus.c
OBJ_B = main_bonus.o error_bonus.o envp_access_bonus.o fd_close_bonus.o is_here_doc_bonus.o pipe_bonus.o
LIBFT = libft.a
LIBFT_DIR = libft
NAME = pipex

.PHONY: all clean fclean re

all : .MAKE_ALL

bonus : .MAKE_BONUS

.MAKE_ALL : $(OBJ) $(LIBFT)
	cp ./$(LIBFT_DIR)/$(LIBFT) ./$(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	rm -rf .MAKE_BONUS
	touch $@

.MAKE_BONUS : $(OBJ_B) $(LIBFT)
	cp ./$(LIBFT_DIR)/$(LIBFT) ./$(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_B) $(LIBFT)
	rm -rf .MAKE_ALL
	touch $@

$(LIBFT) :
	make -C $(LIBFT_DIR) all

clean :
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)
	rm -rf $(LIBFT)
	rm -rf .MAKE_ALL
	rm -rf .MAKE_BONUS

fclean : clean
	rm -rf $(NAME)

re : fclean all