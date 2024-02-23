/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:28:51 by lellong-          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:20 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nb_len(int n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		return (0);
	if (n > 0 && n < 10)
		return (len);
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

long int	ft_iterative_power(int nb, int power)
{
	long int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

char	*dec_to_bin(int nb)
{
	long	n;
	int		i;
	char	*result;

	result = (char *)malloc(sizeof(char) * 17);
	i = 16;
	n = nb;
	while (i >= 0)
	{
		result[i] = n % 2;
		n = n / 2;
		i--;
	}
	return (result);
}
