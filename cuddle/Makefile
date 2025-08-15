##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makes mylib
##

NAME = libcuddle.a
DEBUG = cuddle

SRC = $(filter-out src/main.c,$(wildcard src/*.c))

OBJ = $(SRC:.c=.o)

CFLAGS = -g3

CC = gcc

EXTFLAGS = -L. -lcuddle -lm

RM_LIST = src/*.o src/*.out src/*~ src/*\#

all: $(NAME)
	$(RM) $(RM_LIST)

debug: $(NAME) $(DEBUG)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(DEBUG):
	$(CC) src/main.c -o $(DEBUG) $(CFLAGS) $(EXTFLAGS)
	$(RM) $(RM_LIST)

clean:
	$(RM) $(RM_LIST)

fclean: clean
	$(RM) $(NAME)
	$(RM) cuddle

re: fclean all

test: re debug

coding_style:
	coding-style.sh . .
	cat coding-style-reports.log

push:
	$(RM) coding-style-reports.log
	$(RM) $(NAME)
	$(RM) $(DEBUG)
