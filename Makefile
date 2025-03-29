NAME = push_swap
BONUS_NAME = checker

INCLUDE = include/
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -fsanitize=address

SRC_DIRS = src libft ft_printf
SRC_FILES = $(wildcard $(addsuffix /*.c, $(SRC_DIRS))) main.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

BONUS_DIR = bonus libft ft_printf
BONUS_FILES = $(wildcard $(addsuffix /*.c, $(BONUS_DIR)))
BONUS_OBJ = $(BONUS_FILES:%.c=%.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(NAME)
	lldb ./$(NAME)

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ) $(wildcard libft/*.o ft_printf/*.o)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
