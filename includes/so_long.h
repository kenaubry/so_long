/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:43:28 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/15 19:43:30 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# define MISSING_MAP "Error. Map is missing.\n"
# define TOO_MUCH_ARGS "Error. Too much arguments.\n"
# define OPEN_FAIL "Error\nOpen failed"
# define MAP_NAME_ERROR "Error\nWrong map name"
# define READ_FAIL "Error\nRead failed"
# define MAP_SIZE_ERROR "Error\nWrong map size"
# define MAP_WALLS_ERROR "Error\nMap not surrounded by walls"
# define MAP_EPC_ERROR "Error\nMandatory element missing in the map (E, P or C)"
# define MLX_INIT_ERROR "Error\nCan't load mlx"
# define MLX_WIN_ERROR "Error\nCan't create new window"

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			h;
	int			w;
	int 		pos_x;
	int			pos_y;
	int 		exit;
	int			mvmts;
	//char		*path;
}				t_image;

typedef struct	s_data
{
	void    *mlx;
    void    *win;
	t_image	*player;
	t_image	*player2;//pas encore fini
	t_image	*walls;
	t_image	*collectibles;
	t_image	*exit;
	t_image	*background;
	t_image	*dark;
	int		collect;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fd;
	int		read;
	int		mvmnt;
	int 	direction;
}				t_data; // 5 à free

typedef struct s_keyval
{
	char	key;
	void	(*f)(t_data *mlx);
}				t_keyval;

void		reinit_player_pos(int *x, int *y, t_data *mlx);
void    render_map(t_data *mlx, int first);
void	put_dark(t_data *mlx);
// EXIT

void    ft_error(int error, t_data *mlx);

void   	map_name_error(t_data *mlx);
void    read_error(t_data *mlx);
void	open_error(t_data *mlx);
void	map_size_error(t_data *mlx);
void    map_walls_error(t_data *mlx);
void    map_epc_error(t_data *mlx);
void	mlx_init_error(t_data *mlx);
void    mlx_win_error(t_data *mlx);

int    exit_esc(t_data *mlx);

// PARSING

void    parsing(int ac, char **av, t_data *mlx);

// UTILS

void	ft_putendl_fd(char *s, int fd);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*ft_realloc(void *ptr, int size, int newsize);
size_t	ft_strlen(const char *str);

int len_map(t_data *mlx);

// SO_LONG

void       so_long(t_data *mlx);

// MLX

t_data	*init_mlx(void);
void	free_mlx(t_data *mlx);

// EVENTS

int	key_press(int keycode, t_data *mlx);

// GAME

void    launch_game(t_data *mlx);



static t_keyval const	manage_error[] = {
{0, open_error},
{1, map_name_error},
{2, read_error},
{3, map_size_error},
{4, map_walls_error},
{5, map_epc_error},
{6, mlx_init_error},
{7, mlx_win_error},
{0}
};

#endif
