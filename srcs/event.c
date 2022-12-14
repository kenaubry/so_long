/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:31:39 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/24 20:31:42 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_keycode(int keycode)
{
	if (keycode == UP || keycode == W || keycode == DOWN \
		|| keycode == S || keycode == LEFT || keycode == A \
		|| keycode == RIGHT || keycode == D)
		return (1);
	return (0);
}

int	key_press(int keycode, t_data *mlx)
{
	if (keycode == 65307 || keycode == 17)
		exit_esc(mlx);
	if (valid_keycode(keycode))
		move_player(mlx, keycode);
	return (0);
}
