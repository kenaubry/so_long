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
	printf("free tab\n");
	while (k >= 0)
		free(dest[k--]);
	free(dest);
	return (NULL);
}

static char	**fill_tab(char const *s, char c, char **dest, int k)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	dest = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!dest)
		return (NULL);
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
	dest = fill_tab(s, c, dest, k);
	return (dest);
}

/*
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
static char			**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void			ft_get_next_str(char **next_str, unsigned int *next_str_len,
					char c)
{
	unsigned int i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1))))
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);//attention forbidden function
		i++;
	}
	tab[i] = NULL;
	return (tab);
}*/