NAME = libftprintf.a
MAKEFLAGS = --no-print-directory
CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SRC = ft_strlen.c hex.c ft_printf.c usd.c ft_putnbr.c

OBJ = $(SRC:.c=.o)
	
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


all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "${YELLOW}Ft_printf Created 🥑 ${RESET}"

%.o: %.c
	@echo "${CYAN}🔨  Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}🧹 Removing Object Files...${RESET}"
	@$(RM) $(OBJ)

fclean: clean
	@echo "${RED}🔥 Removing Executable Files...${RESET}"
	@$(RM) $(NAME)
	@echo "${GOLD}✨ All Executables Removed! Everything is Clean! ✅ ${RESET}"

re: fclean all

.PHONY: all clean fclean re
