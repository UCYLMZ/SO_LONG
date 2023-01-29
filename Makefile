
NAME = so_long

SOURCES = main.c

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