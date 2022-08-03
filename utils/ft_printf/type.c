/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:20:46 by kenaubry          #+#    #+#             */
/*   Updated: 2021/12/07 19:20:50 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_id(int n)
{
	int	size;

	size = 0;
	ft_putnbr(n);
	if (n < 0)
	{
		size++;
		n = n * -1;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

int	type_u(unsigned int n)
{
	int				size;
	unsigned int	nb;

	nb = n;
	size = 0;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(n + 48);
	while (nb)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

int	type_s(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

int	type_hexa(unsigned int n, char *base)
{
	static int	size;

	size = 0;
	if (n)
	{
		type_hexa(n / 16, base);
		ft_putchar(base[n % 16]);
		size++;
	}
	return (size);
}

int	type_p(unsigned long i, char *base)
{
	static int	size;

	size = 2;
	if (i)
	{
		type_p(i / 16, base);
		ft_putchar(base[i % 16]);
		size++;
	}
	return (size);
}
