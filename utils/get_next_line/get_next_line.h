/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:45:58 by kenaubry          #+#    #+#             */
/*   Updated: 2021/11/28 11:45:59 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../includes/so_long.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

size_t	ft_strlenn(char *str);
char	*join_gnl(char *line, char *buf, int end);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
void	*ft_realloc(void *ptr, int size, int newsize);

#endif
