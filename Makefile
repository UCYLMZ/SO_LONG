
NAME = so_long

NAME_BONUS = so_long_bonus

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

CC = @gcc

OBJ = $(SOURCES:.c=.o)

OBJ_BONUS = $(SOURCES_BONUS:.c=.o)

RM  = rm -rf

$(NAME): $(OBJ)
	gcc  $(SOURCES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus:
	gcc  $(SOURCES_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean:
	$(RM) *.o $(NAME)

fclean:
	$(RM) *.o $(NAME) &(NAME_BONUS)
re:
	make clean
	make