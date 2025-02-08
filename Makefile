# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =			ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c \
				ft_strchr.c ft_strncmp.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_calloc.c ft_strdup.c ft_strrchr.c ft_strnstr.c \
				ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_substr.c \
				ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
				ft_putendl_fd.c ft_strtrim.c ft_split.c ft_strmapi.c \
				ft_itoa.c ft_striteri.c ft_isspace.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_charcheck.c ft_numcheck.c ft_printf.c \
				get_next_line.c get_next_line_utils.c

# ---------- COLORS AND STUFF ---------- #
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m
CLEAR_LINE = \033[2K\r

TOTAL_SRCS = $(words $(SRCS))
CURRENT = 0

# Object files
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@true

# Rule to compile the main library
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Object file compilation rule
.c.o:
	@$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL_SRCS)))))
	@printf "$(CLEAR_LINE)$(YELLOW)🚧 Compiling $(PERCENT)%% [$(CURRENT)/$(TOTAL_SRCS)] $(CYAN)$<$(NC) 🚧"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and libraries
clean:
	@rm -f $(OBJS)

# Clean all generated files
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re