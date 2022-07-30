/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:32:41 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/24 20:32:44 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && i < (int)ft_strlen(s))
				i++;
		}
		if (s[i] == c)
			i++;
	}
	return (count);
}

static int	len_word(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && i++ < (int)ft_strlen(s))
		len++;
	return (len);
}

static void	*free_tab(char **dest, int k)
{
	while (k >= 0)
		free(dest[k--]);
	free(dest);
	return (NULL);
}

static char	**fill_tab(char const *s, char c, char **dest, int k)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < (int)(ft_strlen(s)))
	{
		if (s[i] != c)
		{
			dest[k] = (char *)malloc(sizeof(char) * (len_word(s, c, i) + 1));
			if (!dest[k])
				return (free_tab(dest, k));
			while (s[i] != c && i < (int)(ft_strlen(s)))
				dest[k][j++] = s[i++];
			dest[k++][j] = '\0';
			j = 0;
		}
	}
	dest[count_word(s, c)] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**dest;

	k = 0;
	if (s == NULL)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!dest)
		return (NULL);
	dest = fill_tab(s, c, dest, k);
	return (dest);
}
