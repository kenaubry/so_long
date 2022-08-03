/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:41:31 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/17 19:41:32 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

int	len_map(t_data *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i] != NULL)
		i++;
	return (i);
}

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
