/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:31:56 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/24 20:31:59 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	*init_imgs(t_data *mlx)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (img == NULL)
	{
		free_mlx(mlx);
		exit(1);
	}
	ft_memset(img, 0, sizeof(t_image));
	return (img);
}

t_data	*init_mlx(t_data *mlx)
{
	t_data	*new;
	int		i;

	i = 0;
	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		exit(1);
	ft_memset(new, 0, sizeof(t_data));
	while (i < TEXT_NBR)
		new->textures[i++] = init_imgs(new);
	return (new);
}

void	*free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

static void	*free_img(t_data *mlx, t_image *img)
{
	if (img)
	{
		if (img->img && img->addr)
			mlx_destroy_image(mlx->mlx, img->img);
		free(img);
	}
}

void	free_mlx(t_data *mlx)
{
	int	i;

	i = 0;
	while (i < TEXT_NBR)
	{
		if (mlx->textures[i] != NULL)
			free_img(mlx, mlx->textures[i]);
		i++;
	}
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	if (mlx->mlx != NULL)
		free(mlx->mlx);
	if (mlx->map != NULL)
		free_map(mlx->map);
	free(mlx);
}
