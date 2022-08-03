/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:51:59 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/03 11:52:01 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_size_error(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	ft_putendl_fd(MAP_SIZE_ERROR, STDERR_FILENO);
	exit(1);
}

void	map_walls_error(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	ft_putendl_fd(MAP_WALLS_ERROR, STDERR_FILENO);
	exit(1);
}

void	map_epc_error(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	ft_putendl_fd(MAP_EPC_ERROR, STDERR_FILENO);
	exit(1);
}

void	missing_map_error(t_data *mlx)
{
	free_mlx(mlx);
	ft_putendl_fd(MISSING_MAP, STDERR_FILENO);
	exit(1);
}

void	fill_map_error(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	ft_putendl_fd(FILL_MAP_ERROR, STDERR_FILENO);
	exit(1);
}
