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
	while (g_manage_error[i].f && g_manage_error[i].key != error)
		i++;
	if (g_manage_error[i].f)
		return (g_manage_error[i].f(mlx));
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
	ft_putendl_fd(GAME_OVER_ERROR, STDERR_FILENO);
	exit(0);
}

void	exit_success(t_data *mlx)
{
	close(mlx->fd);
	free_mlx(mlx);
	ft_putendl_fd(SUCCESS_GAME, STDERR_FILENO);
	exit(0);
}
