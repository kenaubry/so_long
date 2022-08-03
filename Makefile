
NAME = so_long

SRCS =	parsing.c \
		error.c \
		error_args.c \
		error_map.c \
		main.c \
		mlx.c \
		launch_game.c \
		event.c \
		check_map.c \
		mouvements.c \
		render_map.c \
		init_game.c

UTILS = ft_strnstr.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_split.c \
		ft_putendl_fd.c \
		ft_memset.c 
	
GNL = get_next_line.c \
	get_next_line_utils.c

SRCS_DIR = srcs
UTILS_DIR = utils
GNL_DIR = utils/get_next_line

FLAGS = -Wall -Werror -Wextra

SRCS_P = $(addprefix $(SRCS_DIR)/, $(SRCS))
UTILS_P = $(addprefix $(UTILS_DIR)/, $(UTILS))
GNL_P = $(addprefix $(GNL_DIR)/, $(GNL))

OBJ = $(SRCS_P:.c=.o)
OBJ_U = $(UTILS_P:.c=.o)
OBJ_G = $(GNL_P:.c=.o)

CC = gcc -g 

$(NAME): $(OBJ) $(OBJ_U) $(OBJ_G)
	@make -C utils/ft_printf
	@$(CC) -O3 -o $(NAME) $(OBJ) $(OBJ_U) $(OBJ_G) utils/ft_printf/libftprintf.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	@$(CC) -I/usr/include -Imlx_linux -c $< -o $@

clean :
	@make clean -C utils/ft_printf
	@rm -rf $(OBJ) $(OBJ_U) $(OBJ_G)
	@echo "clean done"

fclean : clean
	@make fclean -C utils/ft_printf
	@rm -rf $(NAME)
	@echo "fclean done"

all : $(NAME)

re : fclean all
	@echo "make re done"

.PHONY: re clean fclean all         