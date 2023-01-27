NAME = so_long

PRINTF_A = ./SRC/PRINTF/libftprintf.a

GNL_A = ./SRC/GET_NEXT_LINE/libftgnl.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(PRINTF_A) $(GNL_A)

$(PRINTF_A):
	make -C ./SRC/PRINTF

$(GNL_A):
	make -C ./SRC/GET_NEXT_LINE



