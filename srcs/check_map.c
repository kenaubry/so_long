/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:48:54 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/03 11:48:56 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_name(char *map, t_data *mlx)
{
	if (ft_strlen(map) < 4 || strcmp(map + ft_strlen(map) - 4, ".ber") != 0)
		ft_error(1, mlx);
}

void	check_map_epc(t_data *mlx)
{
	int	i;
	int	j;
	int	element[3];

	element[EXIT] = 0;
	element[COLLECTIBLES] = 0;
	element[PLAYER] = 0;
	i = 1;
	j = 1;
	while (mlx->map[i] != NULL)
	{
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'E')
				element[EXIT]++;
			if (mlx->map[i][j] == 'C')
				element[COLLECTIBLES]++;
			if (mlx->map[i][j] == 'P')
				element[PLAYER]++;
			j++;
		}
		i++;
		j = 1;
	}
	if (element[EXIT] == 0 || element[COLLECTIBLES] == 0 \
		|| element[PLAYER] == 0)
		ft_error(5, mlx);
}

void	check_map_size(t_data *mlx)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i] != NULL)
	{
		if (ft_strlen(mlx->map[i]) != len)
			ft_error(3, mlx);
		i++;
	}
}

void	check_map_walls(t_data *mlx)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i] != NULL)
	{
		if (mlx->map[i][len - 1] != '1' || mlx->map[i][0] != '1')
			ft_error(4, mlx);
		i++;
	}
	len = i - 1;
	i = 0;
	while (mlx->map[0][i] != '\0')
	{
		if (mlx->map[0][i] != '1')
			ft_error(4, mlx);
		i++;
	}
	i = 0;
	while (mlx->map[len][i] != '\0')
	{
		if (mlx->map[len][i] != '1')
			ft_error(4, mlx);
		i++;
	}
}

void	is_map_valid(char *map_name, t_data *mlx)
{
	check_map_name(map_name, mlx);
	mlx->map = map_to_tab(map_name, mlx);
	check_map_size(mlx);
	check_map_walls(mlx);
	check_map_epc(mlx);
}
