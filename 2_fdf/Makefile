CC = cc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -L./ -lmlx -framework OpenGL -framework Appkit
SRC = \
	main.c check_input.c set_xyz_color.c rotate.c final_set_xy.c draw_line.c dda.c get_trgb.c split.c utils.c\
	get_next_line.c get_next_line_utils.c
OBJ = \
	main.o check_input.o set_xyz_color.o rotate.o final_set_xy.o draw_line.o dda.o get_trgb.o split.o utils.o\
	get_next_line.o get_next_line_utils.o
SRC_BONUS = \
	main_bonus.c check_input_bonus.c set_xyz_color_bonus.c rotate_bonus.c final_set_xy_bonus.c\
	draw_line_bonus.c dda_bonus.c update_bonus.c key_hook_bonus.c key_hook_move_bonus.c key_hook_rotate_bonus.c\
	key_hook_scale_bonus.c split_bonus.c utils_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c get_trgb_bonus.c
OBJ_BONUS = \
	main_bonus.o check_input_bonus.o set_xyz_color_bonus.o rotate_bonus.o final_set_xy_bonus.o\
	draw_line_bonus.o dda_bonus.o update_bonus.o key_hook_bonus.o key_hook_move_bonus.o key_hook_rotate_bonus.o\
	key_hook_scale_bonus.o split_bonus.o utils_bonus.o get_next_line_bonus.o get_next_line_utils_bonus.o get_trgb_bonus.o
MAIN = fdf
MLX = libmlx.dylib 
MLX_DIR = mlx

.PHONY: all clean fclean re bonus

all : .MAKE_ALL

bonus : .MAKE_BONUS

.MAKE_ALL : $(OBJ) $(MLX)
	cp ./$(MLX_DIR)/$(MLX) $(MLX)
	$(CC) $(CFLAGS) $(OPTIONS) -o fdf $(OBJ) $(MLX)
	rm -rf .MAKE_BONUS
	touch $@

.MAKE_BONUS : $(OBJ_BONUS) $(MLX)
	cp ./$(MLX_DIR)/$(MLX) $(MLX)
	$(CC) $(CFLAGS) $(OPTIONS) -o fdf $(OBJ_BONUS) $(MLX)
	rm -rf .MAKE_ALL
	touch $@

$(MLX) :
	make -C $(MLX_DIR) all 

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	make -C $(MLX_DIR) clean
	rm -rf $(MLX)
	rm -rf .MAKE_ALL
	rm -rf .MAKE_BONUS

fclean: clean
	rm -rf $(MAIN)

re: fclean all