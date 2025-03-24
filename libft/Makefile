NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_isascii.c ft_isprint.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstmap.c\
OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

# Rule to build the library
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

# Rule to compile object files
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	$(RM) $(OBJ) $(BONUS_OBJS)

# Rule to clean everything (object files and the library)
fclean: clean
	$(RM) $(NAME)

# Rule to rebuild the library
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
