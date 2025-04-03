NAME = push_swap
BONUS_NAME = checker

BUILD = build
INCLUDE = -I./include
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)
LIB = -Llibft -lft -Lft_printf -lftprintf

SRC_DIRS = src
SRC_FILES = checker.c free_stack.c print.c push_a.c reverse_rotate.c \
			sorting_functions.c finder.c main.c push.c push_swap.c rotate.c swap.c
OBJS = $(patsubst %.c, $(BUILD)/%.o, $(SRC_FILES))

BONUS_DIR = bonus
BONUS_FILES = checker_bonus.c main_bonus.c push_bonus.c rotate_bonus.c \
				get_next_line.c push_a_bonus.c  reverse_rotate_bonus.c  swap_bonus.c
BONUS_OBJ = $(patsubst %.c, $(BUILD)/%.o, $(BONUS_FILES))

all: build lib $(NAME)

lib:
	make -C libft
	make bonus -C libft
	make -C ft_printf

build:
	mkdir -p $(BUILD)

bonus: build lib $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB) -o $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(BUILD)/%.o: $(SRC_DIRS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -rf $(BUILD)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus lib build
