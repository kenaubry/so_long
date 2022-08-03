/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:42:04 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/17 18:42:05 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*join_map_str(char *map_str, char *buf, t_data *mlx)
{
	char	*tmp;

	tmp = map_str;
	map_str = ft_strjoin(map_str, buf);
	free(tmp);
	if (map_str == NULL)
	{
		close(mlx->fd);
		free_mlx(mlx);
		exit(1);
	}
	return (map_str);
}

static int	read_or_error(int fd, char *buf, t_data *mlx)
{
	int	reader;

	reader = read(fd, buf, 1);
	if (reader == -1)
		ft_error(2, mlx);
	return (reader);
}

static char	**split_map_str(t_data *mlx, char *map_str)
{
	mlx->map = ft_split(map_str, '\n');
	free(map_str);
	if (mlx->map == NULL)
	{
		close(mlx->fd);
		free(mlx->map);
		ft_error(10, mlx);
	}
	return (mlx->map);
}

char	**map_to_tab(char *map_name, t_data *mlx)
{
	char	buf[1];
	char	*map_str;
	int		reader;

	mlx->fd = open(map_name, O_RDONLY);
	if (mlx->fd == -1)
		ft_error(0, mlx);
	map_str = NULL;
	reader = read_or_error(mlx->fd, buf, mlx);
	while (reader != 0)
	{
		map_str = join_map_str(map_str, buf, mlx);
		reader = read_or_error(mlx->fd, buf, mlx);
	}
	return (split_map_str(mlx, map_str));
}

void	parsing(int ac, char **av, t_data *mlx)
{
	if (ac == 1)
		ft_error(8, mlx);
	else if (ac > 2)
		ft_error(9, mlx);
	else
		is_map_valid(av[1], mlx);
}
