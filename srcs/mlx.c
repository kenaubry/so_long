/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:31:56 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/01 00:37:36 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	*init_imgs(void)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (img == NULL)
		exit(1); // leaks si on sort de la fonction car tu as allouer new dans init_mlx

	// fais un memset sur ton image pour initialiser toutes les valeurs a 0
	img->addr = NULL;
	img->img = NULL;
	img->pos_x = 0;
	img->pos_y = 0;
	return (img);
}

t_data	*init_mlx(void)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		exit(1);
	// fais un memset(new, 0, sizeof(t_data)); au lieu de tout mettre a NULL ou 0;
	new->mlx = NULL;
	new->win = NULL;
	new->read = 1;
	new->map = NULL;
	new->mvmnt = 0;
	new->exit = 0;
	new->mvmnt = 0;
	new->direction = 0;
	new->dark = init_imgs(); // leaks si echoues
	new->player2 = init_imgs(); // leaks si echoues
	new->walls = init_imgs(); // leaks si echoues
	new->collectibles = init_imgs(); // leaks si echoues
	new->exit = init_imgs(); // leaks si echoues
	new->player = init_imgs(); // leaks si echoues
	new->background = init_imgs(); // leaks si echoues
	return (new);
}

static void	*free_map(char **map)
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
	if (img->img && img->addr) // segfault si img == NULL
		mlx_destroy_image(mlx->mlx, img->img);
	img->img = NULL;
	img->addr = NULL;
	if (img) // si img == NULL tu as deja segfault des la premiere ligne
		free(img);
}

void	free_mlx(t_data *mlx)
{
	if (mlx->player != NULL)
		free_img(mlx, mlx->player);
	if (mlx->player2 != NULL)
		free_img(mlx, mlx->player2);
	if (mlx->dark != NULL)
		free_img(mlx, mlx->dark);
	if (mlx->walls != NULL)
		free_img(mlx, mlx->walls);
	if (mlx->collectibles != NULL)
		free_img(mlx, mlx->collectibles);
	if (mlx->exit != NULL)
		free_img(mlx, mlx->exit);
	if (mlx->background != NULL)
		free_img(mlx, mlx->background);
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
