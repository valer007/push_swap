NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIRS = src libft ft_printf
SRC_FILES = $(wildcard $(addsuffix /*.c, $(SRC_DIRS))) main.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_FILES): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(wildcard libft/*.o ft_printf/*.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
