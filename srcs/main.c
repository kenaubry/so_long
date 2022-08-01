/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:32:06 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/01 00:36:03 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	*mlx;

	mlx = init_mlx();
	parsing(ac, av, mlx);
	launch_game(mlx);
	return (0);
}
