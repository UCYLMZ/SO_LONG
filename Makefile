
NAME = so_long

SOURCES = main.c path_wall_check.c utils.c map_check.c \
		  map_info.c ./SRC/GET_NEXT_LINE/libftgnl.a	   \
		  utils_free.c movement.c utils_textures.c

CC = @gcc

OBJ = $(SRCS:.c=.o)

RM  = rm -rf

$(NAME): $(OBJ)
	gcc $(SOURCES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) *.o $(NAME)

fclean:
	$(RM) *.o $(NAME)
re:
	make clean
	make