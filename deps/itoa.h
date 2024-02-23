/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:40:31 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/03 18:17:45 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_H
# define ITOA_H

long int		len_number(long int nb);
char			int_to_char(long int mod);
void			fill_words(long int nb, long int len_nb, char *result_nb);
char			*ft_itoa(int n);

#endif