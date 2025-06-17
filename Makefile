NAME = push_swap
BONUS_NAME = checker
MAKEFLAGS = --no-print-directory
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
BONUS_FILES = checker_bonus.c main_bonus.c push_bonus.c rotate_bonus.c check_space.c\
				get_next_line.c push_a_bonus.c  reverse_rotate_bonus.c  swap_bonus.c free_stack_bonus.c
BONUS_OBJ = $(patsubst %.c, $(BUILD)/%.o, $(BONUS_FILES))

RESET			= \033[0m
BLUE			= \033[34m
YELLOW			= \033[38;2;255;239;0m
APPLE_GREEN		= \033[38;2;141;182;0m
PINK			= \033[38;2;255;105;180m
RED				= \033[31m
CYAN			= \033[38;2;0;255;255m
VIOLET			= \033[38;2;138;43;226m
GOLD			= \033[38;2;255;215;0m
MAGENTA			= \033[38;2;255;0;255m

all: build lib $(NAME)

lib:
	@make -C libft
	@make -C ft_printf

build:
	@mkdir -p $(BUILD)

bonus: build lib $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	@echo "${VIOLET}💻 Compiling Checker...${RESET}"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB) -o $(BONUS_NAME)
	@echo "${YELLOW}✨ Checker Executable Created 🥑 ${RESET}"

$(NAME): $(OBJS)
	@echo "${PINK}💻 Compiling Push_Swap...${RESET}"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "${YELLOW}✨ Push_Swap Executable Created 🥑 ${RESET}"

$(BUILD)/%.o: $(SRC_DIRS)/%.c
	@echo "${CYAN}🔨  Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@


$(BUILD)/%.o: $(BONUS_DIR)/%.c
	@echo "${RED}🔨  Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}🧹 Removing Object Files...${RESET}"
	@make clean -C libft
	@make clean -C ft_printf
	@rm -rf $(BUILD)

fclean: clean
	@echo "${RED}🔥 Removing Executable Files...${RESET}"
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "${GOLD}✨ All Executables Removed! Everything is Clean! ✅ ${RESET}"
	
re: fclean all

.PHONY: all clean fclean re bonus lib build
