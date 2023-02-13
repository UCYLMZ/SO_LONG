NAME = so_long

NAME_BONUS = so_long_bonus

MLX = ./SRC/mlx/libmlx.a

GNL = ./SRC/GET_NEXT_LINE/libftgnl.a

SOURCES = main.c path_wall_check.c utils.c map_check.c \
		  map_info.c ./SRC/GET_NEXT_LINE/libftgnl.a	   \
		  utils_free.c movement.c utils_textures.c	   \
		  utils_print.c

SOURCES_BONUS = main_bonus.c map_info_bonus.c utils_bonus.c			\
				map_check_bonus.c ./SRC/GET_NEXT_LINE/libftgnl.a	\
				path_wall_check_bonus.c utils_free_bonus.c			\
				utils_print_bonus.c mlx_handle_bonus.c				\
				loop_animate_bonus.c coin_animator_bonus.c			\
				player_movement_bonus.c animate_checker.c			\
				enemy_animate_bonus.c utils_animate_bonus.c

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit -L./SRC/mlx -lmlx 

$(NAME): $(SOURCES) $(MLX) $(GNL)
		@gcc $(CCFLAGS) $(MLXFLAGS) $(GNL) $(SOURCES) -o $(NAME)

all: $(MLX) $(GNL) $(NAME) bonus

bonus: $(MLX) $(GNL) $(SOURCES_BONUS)
		@gcc $(CCFLAGS) $(MLXFLAGS) $(GNL) $(SOURCES_BONUS) -o $(NAME_BONUS)

$(MLX):
	@make -C ./SRC/mlx
$(GNL):
	@make -C ./SRC/GET_NEXT_LINE

clean:
	@rm -rf ./SRC/mlx/*.o
	@rm -rf ./SRC/GET_NEXT_LINE/*.o

fclean: clean
	@rm -rf ./SRC/mlx/*.a
	@rm -rf ./SRC/GET_NEXT_LINE/*.a
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re