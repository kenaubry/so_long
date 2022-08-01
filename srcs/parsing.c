/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:42:04 by kenaubry          #+#    #+#             */
/*   Updated: 2022/08/01 01:05:48 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_name(char *map, t_data *mlx)
{
	char	*ext;

	ext = ft_strnstr(map, ".ber", ft_strlen(map));
	// tu ne cherches pas a voir si .ber est dans map, c'est un peu moche
	// tu veux regarder si les quatres derniers caracteres sont .ber
	// le code ressemble a ca

	// if (strlen(map) < 4 || ft_strcmp(map + ft_strlen(map) - 4, ".ber") != 0)
	// 	ft_error(1, mlx);


	if (ext == NULL || *(ext + 4) != '\0')
		ft_error(1, mlx);
}

char	**map_to_tab(t_data *mlx)
{
	char	buf[1]; // pourquoi lire 1 caractere par 1 caractere ? utilise ton GNL
	char	*map_str;
	char	*tmp;

	map_str = NULL;
	mlx->read = read(mlx->fd, buf, 1); // pourquoi le read est ici ?
										// pourquoi tu as stocker dans ta structure le retour de read ? alors que tu ne le reutilises pas ?
	if (mlx->read == -1)
		ft_error(2, mlx);
	// fais une autre fonction pour les 3 premieres lignes de ton while , ca t'economiseras les lignes que tu essayes d'eco avec ton read dans ta structure
	while (mlx->read != 0)
	{
		tmp = map_str;
		map_str = ft_strjoin(map_str, buf); // tu ne check pas si map_str est NULL, c'est un segfault potentiel
		free(tmp);
		mlx->read = read(mlx->fd, buf, 1); // pourquoi tu stocke le fd dans ta structure ?
		if (mlx->read == -1)
			ft_error(2, mlx);
	}
	mlx->map = ft_split(map_str, '\n'); // si tu as une erreur dans le split, tu vas renvoyer NULL et tu vas continer a run alors que tu devrais exit
	free(map_str);
	return (mlx->map);
}

char	**fill_map(char *map_name, t_data *mlx)
{
	mlx->fd = open(map_name, O_RDONLY);
	if (mlx->fd == -1)
		ft_error(0, mlx);
	mlx->map = map_to_tab(mlx);
	return (mlx->map); // pourquoi renvoyer pour reassigner la meme valeur ?
}

void	check_map_size(t_data *mlx)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(mlx->map[0]); // SEGFAULT du a ton join dans map_to_tab
	while (mlx->map[i] != NULL)
	{
		if (ft_strlen(mlx->map[i]) != len)
			ft_error(3, mlx);
		i++;
	}
}

void	check_map_walls(t_data *mlx)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i] != NULL)
	{
		if (mlx->map[i][len - 1] != '1' || mlx->map[i][0] != '1')
			ft_error(4, mlx);
		i++;
	}
	len = i - 1;
	i = 0;
	while (mlx->map[0][i] != '\0')
	{
		if (mlx->map[0][i] != '1')
			ft_error(4, mlx);
		i++;
	}
	i = 0;
	while (mlx->map[len][i] != '\0')
	{
		if (mlx->map[len][i] != '1')
			ft_error(4, mlx);
		i++;
	}
}

void	check_map_epc(t_data *mlx)
{
	int	i;
	int	j;
	int	ecp[3]; // NON

	ecp[0] = 0;
	ecp[1] = 0;
	ecp[2] = 0;
	i = 1;
	j = 1;
	while (mlx->map[i] != NULL)
	{
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'E')
				ecp[0]++;
			if (mlx->map[i][j] == 'C')
				ecp[1]++;
			if (mlx->map[i][j] == 'P')
				ecp[2]++;
			j++;
		}
		i++;
		j = 1;
	}
	if (ecp[0] == 0 || ecp[1] == 0 || ecp[2] == 0)
		ft_error(5, mlx);
}

static void	check_map_content(char *map_name, t_data *mlx)
{
	mlx->map = fill_map(map_name, mlx); // si mlx est null alors segfault, mais tu dois deja avoir check mlx avant de lancer cette fonction
	// pourquoi faire mlx->map = fill_map(map_name, mlx) alors que tu l'as deja fait dans fill_map ?
	check_map_size(mlx); // j'arrete de checker le parsing, je n'aime pas ca je passe a la suite
	check_map_walls(mlx);
	check_map_epc(mlx);
}

static void	is_map_valid(char *map_name, t_data *mlx)
{
	check_map_name(map_name, mlx);
	check_map_content(map_name, mlx);
}

void	parsing(int ac, char **av, t_data *mlx)
{
	if (ac == 1)
	{
		write(2, MISSING_MAP, 23);
		free_mlx(mlx); // segfault
		exit(1);
	}
	else if (ac > 2)
	{
		write(2, TOO_MUCH_ARGS, 27);
		free_mlx(mlx); // segfault
		exit(1);
	}
	else
		is_map_valid(av[1], mlx);
}
