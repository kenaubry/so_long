/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:51:52 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/03 11:51:55 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	too_arg_error(t_data *mlx)
{
	free_mlx(mlx);
	ft_putendl_fd(TOO_MUCH_ARGS, STDERR_FILENO);
	exit(1);
}
