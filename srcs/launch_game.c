/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:31:47 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/24 20:31:50 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_sprite(t_data *mlx, int i, int j, int sprite)
{
	if (sprite == player && mlx->direction != 0)
		sprite = 1;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->textures[sprite]->img, \
		j * SPRITE_SIZE, i * SPRITE_SIZE);
}

int	is_dark(t_data *mlx, int i, int j)
{
	if (mlx->map[i][j] == 'P')
		return (0);
	if (j < ft_strlen(mlx->map[0]))
	{
		if (mlx->map[i][j + 1] == 'P')
			return (0);
	}
	if (j > 0)
	{
		if (mlx->map[i][j - 1] == 'P' && j != 0)
			return (0);
	}
	if (i < (len_map(mlx) - 1))
	{
		if (mlx->map[i + 1][j] == 'P')
			return (0);
	}
	if (i > 0 && j > 0)
	{
		if (mlx->map[i - 1][j - 1] == 'P')
			return (0);
	}
	if (i > 0 && j < ft_strlen(mlx->map[0]))
	{
		if (mlx->map[i - 1][j + 1] == 'P')
			return (0);
	}
	if (i < (len_map(mlx) - 1) && j < ft_strlen(mlx->map[0]))
	{
		if (mlx->map[i + 1][j + 1] == 'P')
			return (0);
	}
	if (i < (len_map(mlx) - 1) && j > 0)
	{
		if (mlx->map[i + 1][j - 1] == 'P')
			return (0);
	}
	if (i > 0)
	{
		if (mlx->map[i - 1][j] == 'P')
			return (0);
	}
	else
		return (1);
}

void	put_dark(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (is_dark(mlx, i, j))
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
				mlx->textures[dark]->img, j * SPRITE_SIZE, i * SPRITE_SIZE);
			j++;
		}
		i++;
	}
}

void	render_map(t_data *mlx)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (mlx->map[i] != NULL)
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '1')
				put_sprite(mlx, i, j, walls);
			else if (mlx->map[i][j] == 'P')
				put_sprite(mlx, i, j, player);
			else if (mlx->map[i][j] == 'C')
				put_sprite(mlx, i, j, collectibles);
			else if (mlx->map[i][j] == 'E')
				put_sprite(mlx, i, j, exit_s);
			else
				put_sprite(mlx, i, j, background);
			j++;
		}
		j = 0;
		i++;
	}
	put_dark(mlx);
}

void	launch_game(t_data *mlx)
{
	render_map(mlx);
	mlx_key_hook(mlx->win, key_press, mlx);
	mlx_hook(mlx->win, 17, 0, exit_esc, mlx);
	mlx_loop(mlx->mlx);
}
