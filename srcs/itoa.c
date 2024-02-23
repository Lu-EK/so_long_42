/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:56:28 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/04 13:38:43 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

long int	len_number(long int nb)
{
	if (nb < 0)
		return (1 + len_number(nb * (-1)));
	if (nb > 9)
		return (1 + len_number(nb / 10));
	return (1);
}

char	int_to_char(long int mod)
{
	return (mod + 48);
}

void	fill_words(long int nb, long int len_nb, char *result_nb)
{
	long int	div;
	long int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (nb > 9)
		fill_words(div, len_nb - 1, result_nb);
	result_nb[len_nb] = int_to_char(mod);
}

char	*ft_itoa(int n)
{
	long int	nb;
	long int	len_nb;
	char		*result_nb;

	nb = n;
	len_nb = len_number(nb);
	result_nb = malloc(sizeof(char) * (len_nb + 1));
	if (!result_nb)
		return (NULL);
	if (nb < 0)
	{
		result_nb[0] = '-';
		nb *= -1;
	}
	fill_words(nb, len_nb - 1, result_nb);
	result_nb[len_nb] = '\0';
	return (result_nb);
}
