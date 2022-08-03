/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:54:43 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/03 11:54:45 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	go_up(t_data *mlx)
{
	int	pos_y;
	int	pos_x;

	pos_y = mlx->textures[player]->pos_y - 1;
	pos_x = mlx->textures[player]->pos_x;
	if (mlx->map[pos_y][pos_x] != '1')
		reinit_map(mlx, 'w', mlx->map[pos_y][pos_x]);
}

static void	go_down(t_data *mlx)
{
	int	pos_y;
	int	pos_x;

	pos_y = mlx->textures[player]->pos_y + 1;
	pos_x = mlx->textures[player]->pos_x;
	if (mlx->map[pos_y][pos_x] != '1')
		reinit_map(mlx, 's', mlx->map[pos_y][pos_x]);
}

static void	go_left(t_data *mlx)
{
	int	pos_y;
	int	pos_x;

	pos_y = mlx->textures[player]->pos_y;
	pos_x = mlx->textures[player]->pos_x - 1;
	mlx->direction = 1;
	if (mlx->map[pos_y][pos_x] != '1')
		reinit_map(mlx, 'a', mlx->map[pos_y][pos_x]);
}

static void	go_right(t_data *mlx)
{
	int	pos_y;
	int	pos_x;

	pos_y = mlx->textures[player]->pos_y;
	pos_x = mlx->textures[player]->pos_x + 1;
	mlx->direction = 0;
	if (mlx->map[pos_y][pos_x] != '1')
		reinit_map(mlx, 'd', mlx->map[pos_y][pos_x]);
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
