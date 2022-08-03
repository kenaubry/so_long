/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:57:06 by kenaubry          #+#    #+#             */
/*   Updated: 2021/12/16 14:57:10 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (s[0] == 0)
		return (NULL);
	while (s[i] && s[i] != (char)c && i < BUFFER_SIZE)
		i++;
	if ((char)c == s[i])
		return (&s[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	src++;
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

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_cpy;

	s_cpy = s;
	while (n--)
		*s_cpy++ = 0;
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != '\n' && i < BUFFER_SIZE)
		i++;
	return (i);
}
