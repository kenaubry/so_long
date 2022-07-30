/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:31:39 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/24 20:31:42 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reinit_player_pos(int *x, int *y, t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}

void	reinit_map(t_data *mlx, char direction, char element)
{
	static int	was_exit;
	char		is_exit;

	if (was_exit == 1)
		is_exit = 'E';
	else
		is_exit = '0';
	if (element == 'C')
		mlx->collect -= 1;
	mlx->mvmnt += 1;
	printf("mouvements = %d\n", mlx->mvmnt);
	if (element == 'E' && mlx->collect == 0)
		exit_esc(mlx);
	if (direction == 'w')
	{
		mlx->map[mlx->player->pos_y][mlx->player->pos_x] = is_exit;
		mlx->map[mlx->player->pos_y - 1][mlx->player->pos_x] = 'P';
	}
	if (direction == 's')
	{
		mlx->map[mlx->player->pos_y][mlx->player->pos_x] = is_exit;
		mlx->map[mlx->player->pos_y + 1][mlx->player->pos_x] = 'P';
	}
	if (direction == 'a')
	{
		mlx->map[mlx->player->pos_y][mlx->player->pos_x] = is_exit;
		mlx->map[mlx->player->pos_y][mlx->player->pos_x - 1] = 'P';
	}
	if (direction == 'd')
	{
		mlx->map[mlx->player->pos_y][mlx->player->pos_x] = is_exit;
		mlx->map[mlx->player->pos_y][mlx->player->pos_x + 1] = 'P';
	}
	if (element == 'E')
		was_exit = 1;
	else
		was_exit = 0;
	reinit_player_pos(&mlx->player->pos_x, &mlx->player->pos_y, mlx);
	render_map(mlx, 1);
}

void	go_up(t_data *mlx)
{
	if (mlx->map[mlx->player->pos_y - 1][mlx->player->pos_x] != '1')
		reinit_map(mlx, 'w', mlx->map[mlx->player->pos_y - 1][mlx->player->pos_x]);
}

void	go_down(t_data *mlx)
{
	if (mlx->map[mlx->player->pos_y + 1][mlx->player->pos_x] != '1')
		reinit_map(mlx, 's', mlx->map[mlx->player->pos_y + 1][mlx->player->pos_x]);
}

void	go_left(t_data *mlx)
{
	mlx->direction = 1;
	if (mlx->map[mlx->player->pos_y][mlx->player->pos_x - 1] != '1')
		reinit_map(mlx, 'a', mlx->map[mlx->player->pos_y][mlx->player->pos_x - 1]);
}

void	go_right(t_data *mlx)
{
	mlx->direction = 0;
	if (mlx->map[mlx->player->pos_y][mlx->player->pos_x + 1] != '1')
		reinit_map(mlx, 'd', mlx->map[mlx->player->pos_y][mlx->player->pos_x + 1]);
}

int	valid_keycode(int keycode)
{
	if (keycode == UP || keycode == W || keycode == DOWN \
		|| keycode == S || keycode == LEFT || keycode == A \
		|| keycode == RIGHT || keycode == D)
		return (1);
	return (0);
}

void	move_player(t_data *mlx, int keycode)
{
	if (keycode == UP || keycode == W)
		go_up(mlx);
	if (keycode == DOWN || keycode == S)
		go_down(mlx);
	if (keycode == LEFT || keycode == A)
		go_left(mlx);
	if (keycode == RIGHT || keycode == D)
		go_right(mlx);
}

int	key_press(int keycode, t_data *mlx)
{
	if (keycode == 65307 || keycode == 17)
		exit_esc(mlx);
	if (valid_keycode(keycode))
		move_player(mlx, keycode);
	return (0);
}
