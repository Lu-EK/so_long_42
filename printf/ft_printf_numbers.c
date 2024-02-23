/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:08:35 by lellong-          #+#    #+#             */
/*   Updated: 2022/12/22 13:26:30 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(size_t pointeur)
{
	int		i;
	int		len;
	char	nombre[25];

	i = 0;
	len = 2;
	if (pointeur == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	while (pointeur != 0)
	{
		nombre[i++] = "0123456789abcdef"[pointeur % 16];
		pointeur = pointeur / 16;
		len++;
	}
	i--;
	while (i >= 0)
		ft_putchar(nombre[i--]);
	return (len);
}

int	ft_hexamin(long long n)
{
	int		i;
	int		len;
	char	nombre[30];
	char	*base;

	base = "0123456789abcdef";
	len = 0;
	i = 0;
	if (n == 0)
		len += ft_putchar('0');
	while (n != 0)
	{
		nombre[i++] = base[n % 16];
		n = n / 16;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(nombre[i--]);
		len++;
	}
	return (len);
}

int	ft_hexamaj(unsigned int n)
{
	int		i;
	int		len;
	char	nombre[30];
	char	*base;

	base = "0123456789ABCDEF";
	len = 0;
	i = 0;
	if (n == 0)
		len += ft_putchar('0');
	while (n != 0)
	{
		nombre[i++] = base[n % 16];
		n = n / 16;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(nombre[i--]);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long	nb1;
	int		len;

	len = 0;
	nb1 = n;
	if (nb1 < 0)
	{
		nb1 = -nb1;
		write (1, "-", 1);
		len++;
	}
	if (nb1 > 9)
	{
		len += ft_putnbr(nb1 / 10);
		len += ft_putchar(nb1 % 10 + 48);
	}
	else
	{
		ft_putchar(nb1 % 10 + 48);
		len++;
	}
	return (len);
}

int	ft_putu(int n)
{
	long		nb1;
	long int	len;

	len = 0;
	nb1 = n;
	if (n == 0)
		len = 0;
	if (n < 0)
	{
		len = 10;
		nb1 = 4294967295 + n + 1;
	}
	if (nb1 > 9)
	{
		len += nb_len(n);
		ft_putnbr(nb1 / 10);
		ft_putchar(nb1 % 10 + 48);
	}
	else
	{
		len += ft_putchar(nb1 % 10 + 48);
	}
	return (len);
}
