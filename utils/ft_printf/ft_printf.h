/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:44:42 by kenaubry          #+#    #+#             */
/*   Updated: 2021/12/06 14:44:44 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int		ft_putchar(char c);
int		ft_putstr(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen_printf(const char *str);
void	ft_putnbr(int n);

int		type_id(int n);
int		type_s(char *s);
int		type_hexa(unsigned int n, char *base);
int		type_p(unsigned long i, char *base);
int		type_u(unsigned int n);

int		fill_arg(char type, va_list arg);
int		ft_printf(const char *input, ...);

#endif