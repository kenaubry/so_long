/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:22:39 by kenaubry          #+#    #+#             */
/*   Updated: 2021/12/07 16:22:41 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_xp(char type, va_list arg)
{
	unsigned int	ui;
	unsigned long	ul;

	if (type == 'x')
	{
		ui = (va_arg(arg, unsigned int));
		if (ui == 0)
			return (ft_putchar('0'));
		return (type_hexa(ui, "0123456789abcdef"));
	}
	else if (type == 'X')
	{
		ui = (va_arg(arg, unsigned int));
		if (ui == 0)
			return (ft_putchar('0'));
		return (type_hexa(ui, "0123456789ABCDEF"));
	}
	ft_putstr("0x");
	ul = (va_arg(arg, unsigned long));
	if (ul == 0)
		return (ft_putchar('0') + 2);
	return (type_p(ul, "0123456789abcdef"));
}

int	fill_arg(char type, va_list arg)
{
	unsigned int	ui;

	if (type == 'i' || type == 'd')
		return (type_id(va_arg(arg, int)));
	else if (type == 'u')
	{
		ui = va_arg(arg, unsigned int);
		if (ui == 0)
			return (ft_putchar('0'));
		return (type_u(ui));
	}
	else if (type == 'x' || type == 'X' || type == 'p')
		return (fill_xp(type, arg));
	else if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (type == 's')
		return (type_s(va_arg(arg, char *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int	index;
	int	size;

	index = 0;
	size = 0;
	va_list(arg);
	va_start(arg, input);
	if (!(ft_strchr(input, '%')))
		return ((ft_putstr(input)));
	while (input[index] != '\0')
	{
		if (input[index] == '%')
		{
			size += fill_arg(input[index + 1], arg);
			index += 1;
		}
		else
		{
			size++;
			ft_putchar(input[index]);
		}
		index++;
	}
	va_end(arg);
	return (size);
}
