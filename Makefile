NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs
INC_DIR = ./include
PRINTF_DIR = $(INC_DIR)/printf
GNL_DIR = $(INC_DIR)/get_next_line

LIBFT_SRCS =	ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c \
				ft_strchr.c ft_strncmp.c ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_calloc.c ft_strdup.c ft_strrchr.c ft_strnstr.c \
				ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_substr.c \
				ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
				ft_putendl_fd.c ft_strtrim.c ft_split.c ft_strmapi.c \
				ft_itoa.c ft_striteri.c

PRINTF_SRCS =	ft_charcheck.c ft_numcheck.c ft_printf.c

GNL_SRCS =		get_next_line.c get_next_line_utils.c

SRCS =	$(addprefix $(SRCS_DIR)/, $(LIBFT_SRCS)) \
		$(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS)) \
		$(addprefix $(GNL_DIR)/, $(GNL_SRCS)) \

OBJS =	$(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re