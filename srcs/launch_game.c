/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:31:47 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/01 17:57:30 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	nb_collectibles(t_data *mlx)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'C')
				collectibles += 1;
			j++;
		}
		i++;
	}
	return (collectibles);
}

void	init_game(t_data *mlx)
{
	mlx->collect = nb_collectibles(mlx);
	reinit_player_pos(&mlx->player->pos_x, &mlx->player->pos_y, mlx);
	mlx->dark->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/dark.xpm", &mlx->dark->w, &mlx->dark->h);
	mlx->dark->addr = mlx_get_data_addr(mlx->dark->img, &mlx->dark->bits_per_pixel, &mlx->dark->line_length, &mlx->dark->endian);
	mlx->player->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/player_right.xpm", &mlx->player->w, &mlx->player->h);
	mlx->player->addr = mlx_get_data_addr(mlx->player->img, &mlx->player->bits_per_pixel, &mlx->player->line_length, &mlx->player->endian);
	mlx->player2->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/player_left.xpm", &mlx->player2->w, &mlx->player2->h);
	mlx->player2->addr = mlx_get_data_addr(mlx->player2->img, &mlx->player2->bits_per_pixel, &mlx->player2->line_length, &mlx->player2->endian);
	mlx->walls->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/walls.xpm", &mlx->walls->w, &mlx->walls->h); // tu ne check pas le retour de la fonction, tu t'expose a un segfault si tu ne le fais pas , de meme pour toutes les fois ou tu appele la fonction
	mlx->walls->addr = mlx_get_data_addr(mlx->walls->img, &mlx->walls->bits_per_pixel, &mlx->walls->line_length, &mlx->walls->endian);
	mlx->collectibles->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/collectibles.xpm", &mlx->collectibles->w, &mlx->collectibles->h);
	mlx->collectibles->addr = mlx_get_data_addr(mlx->collectibles->img, &mlx->collectibles->bits_per_pixel, &mlx->collectibles->line_length, &mlx->collectibles->endian);
	mlx->exit->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/exit.xpm", &mlx->exit->w, &mlx->exit->h);
	mlx->exit->addr = mlx_get_data_addr(mlx->exit->img, &mlx->exit->bits_per_pixel, &mlx->exit->line_length, &mlx->exit->endian);
	mlx->background->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/background.xpm", &mlx->background->w, &mlx->background->h);
	mlx->background->addr = mlx_get_data_addr(mlx->background->img, &mlx->background->bits_per_pixel, &mlx->background->line_length, &mlx->background->endian);
}

void	put_wall(t_data *mlx, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->walls->img, j * 128, i * 128);
}

void	put_player(t_data *mlx, int i, int j)
{
	if (mlx->direction == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player->img, j * 128, i * 128);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player2->img, j * 128, i * 128);
}

void	put_collectibles(t_data *mlx, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->collectibles->img, j * 128, i * 128);
}

// pourquoi ecrire 10 fois le meme code, fais une fonction generique (a mettre en lien avec le fichier opti_struct.c)
//void put_sprite(t_data *mlx, int i, int j, int sprite)
//{
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->textures[sprite], j * SQUARE_SIZE, i * SQUARE_SIZE);
//}

void	put_exit(t_data *mlx, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit->img, j * 128, i * 128);
}

void	put_background(t_data *mlx, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->background->img, j * 128, i * 128);
}

int  is_dark(t_data *mlx, int i, int j)
{
	if (mlx->map[i][j] == 'P')
		return (0);
	if (mlx->map[i][j + 1] == 'P')
		return (0);
	if (mlx->map[i][j - 1] == 'P' && j != 0)
		return (0);
	if (i < (len_map(mlx) - 1) && mlx->map[i + 1][j] == 'P')
		return (0);
	if (i != 0)
	{
		if (mlx->map[i - 1][j - 1] == 'P')
		return (0);
	}
	if (i != 0)
	{
		if (mlx->map[i - 1][j + 1] == 'P')
		return (0);
	}
	if (i < (len_map(mlx) - 1))
	{
		if (mlx->map[i + 1][j + 1] == 'P')
		return (0);
	}
	if (i < (len_map(mlx) - 1))
	{
		if (mlx->map[i + 1][j - 1] == 'P')
		return (0);
	}
	if (i != 0)
	{
		if (mlx->map[i - 1][j] == 'P')
			return (0);
	}
	else
		return (1);
}

void	put_dark(t_data *mlx)
{
	int i;
	int j;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			if (is_dark(mlx, i, j))
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->dark->img, j * 128, i * 128);
			j++;
		}
		i++;
	}
}

void	render_map(t_data *mlx, int first)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (first == 0)
		init_game(mlx); // ca n'as pas sa place ici, tu es sensé le faire dans le main
	while (mlx->map[i] != NULL)
	{
		while (mlx->map[i][j])
		{
				if (mlx->map[i][j] == '1')
					put_wall(mlx, i, j);
				else if (mlx->map[i][j] == 'P')
					put_player(mlx, i, j);
				else if (mlx->map[i][j] == 'C')
					put_collectibles(mlx, i, j);
				else if (mlx->map[i][j] == 'E')
					put_exit(mlx, i, j);
				else
					put_background(mlx, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	put_dark(mlx);
}

void	launch_game(t_data *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == 0)
		ft_error(6, mlx);
	mlx->win = mlx_new_window(mlx->mlx, ft_strlen(mlx->map[0]) * 128, \
						len_map(mlx) * 128, "so_long");
	// define SQUARE_SIZE au lieu de reecrire 128
	if (mlx->win == NULL)
		ft_error(7, mlx);
	render_map(mlx, 0);
	mlx_key_hook(mlx->win, key_press, mlx);
	mlx_hook(mlx->win, 17, 0, exit_esc, mlx);
	mlx_loop(mlx->mlx);
}
