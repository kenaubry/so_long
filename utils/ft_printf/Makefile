NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS =	ft_printf.c \
		utils.c \
		type.c

OUT = $(SRCS:.c=.o)

$(NAME): $(OUT)
		@$(CC) $(FLAGS) -c $(SRCS)
		@ar -rcs $(NAME) $(OUT)

all: $(NAME)

clean:
		@$(RM) $(OUT)

fclean: clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re 