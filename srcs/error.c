/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:31:27 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/24 20:31:32 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int error, t_data *mlx)
{
	int	i;

	i = 0;
	while (manage_error[i].f && manage_error[i].key != error)
		i++;
	if (manage_error[i].f)
		return (manage_error[i].f(mlx));
}

void	open_error(t_data *mlx)
{
	free_mlx(mlx);
	ft_putendl_fd(OPEN_FAIL, STDERR_FILENO);
	exit(1);
}

void	map_name_error(t_data *mlx)
{
	free_mlx(mlx);
	ft_putendl_fd(MAP_NAME_ERROR, STDERR_FILENO);
	exit(1);
}

void	read_error(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	ft_putendl_fd(READ_FAIL, STDERR_FILENO);
	exit(1);
}

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

void	mlx_init_error(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	ft_putendl_fd(MLX_INIT_ERROR, STDERR_FILENO);
	exit(1);
}

void	mlx_win_error(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	ft_putendl_fd(MLX_WIN_ERROR, STDERR_FILENO);
	exit(1);
}

int	exit_esc(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	exit(0);
}
