/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:01:09 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/03 12:01:11 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	swap_case(t_data *mlx, char is_exit, char direction)
{
	int	pos_x;
	int	pos_y;

	pos_x = mlx->textures[player]->pos_x;
	pos_y = mlx->textures[player]->pos_y;
	mlx->map[pos_y][pos_x] = is_exit;
	if (direction == 'w')
		mlx->map[pos_y - 1][pos_x] = 'P';
	if (direction == 's')
		mlx->map[pos_y + 1][pos_x] = 'P';
	if (direction == 'a')
		mlx->map[pos_y][pos_x - 1] = 'P';
	if (direction == 'd')
		mlx->map[pos_y][pos_x + 1] = 'P';
}

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
	ft_printf("mouvements = %d\n", mlx->mvmnt);
	if (element == 'E' && mlx->collect == 0)
		exit_success(mlx);
	swap_case(mlx, is_exit, direction);
	if (element == 'E')
		was_exit = 1;
	else
		was_exit = 0;
	reinit_player_pos(&mlx->textures[player]->pos_x, \
		&mlx->textures[player]->pos_y, mlx);
	render_map(mlx);
}
