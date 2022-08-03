/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:17:50 by kenaubry          #+#    #+#             */
/*   Updated: 2021/11/27 18:17:51 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_cpy;

	s_cpy = s;
	while (n--)
		*s_cpy++ = c;
	return (s);
}
