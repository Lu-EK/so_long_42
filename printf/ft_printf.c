/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- <lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:15:21 by lellong-          #+#    #+#             */
/*   Updated: 2022/11/21 12:44:01 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int	checker(char s, size_t len_str, va_list *args, size_t *index)
{
	len_str = 0;
	if (s == 's')
		len_str += ft_putstr(va_arg(*args, char *));
	else if (s == 'c')
		len_str += ft_putchar(va_arg(*args, int));
	else if (s == 'd' || s == 'i')
		len_str += ft_putnbr(va_arg(*args, int));
	else if (s == 'u')
		len_str += ft_putu(va_arg(*args, int));
	else if (s == 'X')
		len_str += ft_hexamaj(va_arg(*args, unsigned int));
	else if (s == 'x')
		len_str += ft_hexamin(va_arg(*args, unsigned int));
	else if (s == 'p')
		len_str += ft_putptr(va_arg(*args, size_t));
	else if (s == '%')
		len_str += ft_putperc(s);
	else
	{
		(*index)--;
		len_str += ft_putchar('%');
	}
	return (len_str);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		len_str;

	va_start(args, str);
	i = 0;
	len_str = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len_str += checker(str[i], len_str, &args, &i);
			i++;
		}
		else
		{
			len_str += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (len_str);
}
