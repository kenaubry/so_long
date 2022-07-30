/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:29:47 by kenaubry          #+#    #+#             */
/*   Updated: 2021/12/14 14:29:48 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, int size, int newsize)
{
	char	*tmp;
	char	*new;
	int		i;

	tmp = (char *)ptr;
	//printf("tmp = %p, new = %p, ptr = %p\n" ,&tmp, &new, &ptr);
	new = malloc(sizeof(char) * (newsize));
	if (new == NULL)
	{
		if (ptr && size != 0)
			free(ptr);
		return (NULL);
	}
	i = 0;
	while (i <= size)
	{
		new[i] = tmp[i];
		i++;
	}
	if (ptr)
	{
		*(char *)ptr = 0;
		free(ptr);
	}
	return (new);
} 

char	*join_gnl(char *line, char *buf, int end)
{
	char	*dest;
	int		i;
	int		j;
	int		size_malloc;

	i = 0;
	j = 0;
	if (*line == 0 && *buf == 0 && end == 1)
	{
		free(line);
		return (NULL);
	}
	i = ft_strlen(line);
	size_malloc = ft_strlen(line) + ft_strlenn(buf) + end;
	dest = ft_realloc(line, ft_strlen(line), size_malloc);
	while (j < BUFFER_SIZE && buf[j] != '\n' && buf[j])
		dest[i++] = buf[j++];
	if (buf[j] == '\n' && end == 2)
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[256][BUFFER_SIZE + 1];
	int			reader;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	*line = 0;
	reader = 1;
	line = join_gnl(line, buf[fd], 2);
	while (ft_strchr(buf[fd], '\n') == NULL)
	{
		reader = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][reader] = '\0';
		if (reader <= 0)
		{
			*buf[fd] = 0;
			line = join_gnl(line, buf[fd], 1);
			return (line);
		}
		line = join_gnl(line, buf[fd], 2);
	}
	ft_strlcpy(buf[fd], ft_strchr(buf[fd], '\n'), BUFFER_SIZE);
	return (line);
}
