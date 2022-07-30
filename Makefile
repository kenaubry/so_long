
NAME = so_long

SRCS =	parsing.c \
		error.c \
		main.c \
		mlx.c \
		launch_game.c \
		event.c

UTILS = ft_strnstr.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_split.c \
		ft_putendl_fd.c
	
GNL = get_next_line.c \
	get_next_line_utils.c

SRCS_DIR = srcs
UTILS_DIR = utils
GNL_DIR = get_next_line

FLAGS = -Wall -Werror -Wextra

SRCS_P = $(addprefix $(SRCS_DIR)/, $(SRCS))
UTILS_P = $(addprefix $(UTILS_DIR)/, $(UTILS))
GNL_P = $(addprefix $(GNL_DIR)/, $(GNL))

OBJ = $(SRCS_P:.c=.o)
OBJ_U = $(UTILS_P:.c=.o)
OBJ_G = $(GNL_P:.c=.o)

CC = gcc

$(NAME): $(OBJ) $(OBJ_U) $(OBJ_G)
	$(CC) $(FLAGS) -O3 -o $(NAME) $(OBJ) $(OBJ_U) $(OBJ_G) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -c $< -o $@

clean :
	@rm -rf $(OBJ) $(OBJ_U) $(OBJ_G)
	@echo "clean done"

fclean : clean
	@rm -rf $(NAME)
	@echo "fclean done"

leaks : $(OBJ) $(OBJ_U) $(OBJ_G)
	$(CC) $(FLAGS) -fsanitize=address -g3 -o $(NAME) $(OBJ) $(OBJ_U) $(OBJ_G)
	@echo "make leaks done"

all : $(NAME)

re : fclean all
	@echo "make re done"

.PHONY: re clean fclean all         