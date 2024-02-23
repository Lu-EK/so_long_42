/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:36:13 by lellong-          #+#    #+#             */
/*   Updated: 2022/12/22 12:47:50 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putptr(size_t pointeur);
int		ft_putnbr(int n);
int		ft_putperc(char c);
int		ft_hexamaj(unsigned int n);
int		ft_hexamin(long long int n);
int		ft_putu(int n);
int		nb_len(int n);
int		selection(const char *str, va_list args);
int		checker(char s, size_t len_str, va_list *args, size_t *index);
size_t	ft_strlen(const char *str);
char	*dec_to_bin(int nb);

#endif
