/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:12:48 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/03 12:12:50 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_textures(t_data *data)
{
	int	i;

	i = 0;
	(void)g_textures_path;
	while (i < TEXT_NBR)
	{
		data->textures[i]->img = mlx_xpm_file_to_image(data->mlx, \
			g_textures_path[i], &data->textures[i]->w, &data->textures[i]->h);
		if (data->textures[i]->img == NULL)
			return (-1);
		data->textures[i]->addr = mlx_get_data_addr(data->textures[i]->img, \
			&data->textures[i]->bits_per_pixel, \
			&data->textures[i]->line_length, &data->textures[i]->endian);
		if (data->textures[i]->addr == NULL)
			return (-1);
		i++;
	}
	return (0);
}

void	init_game(t_data *mlx)
{
	int	textures;

	mlx->mlx = mlx_init();
	if (mlx->mlx == 0)
		ft_error(6, mlx);
	mlx->win = mlx_new_window(mlx->mlx, ft_strlen(mlx->map[0]) * SPRITE_SIZE, \
						len_map(mlx) * SPRITE_SIZE, "so_long");
	if (mlx->win == NULL)
		ft_error(7, mlx);
	mlx->collect = nb_collectibles(mlx);
	reinit_player_pos(&mlx->textures[player]->pos_x, \
		&mlx->textures[player]->pos_y, mlx);
	textures = open_textures(mlx);
	if (textures == -1)
	{
		close(mlx->fd);
		free_mlx(mlx);
		exit(1);
	}
}
