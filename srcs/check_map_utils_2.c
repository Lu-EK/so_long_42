/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:20:15 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/29 16:39:20 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

void	get_player_position(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < number_of_row(data->filename))
	{
		j = -1;
		while (++j < number_of_col(data->filename))
		{
			if (data->verif_map[i][j] == 'P')
			{
				data->p_p.y = i;
				data->p_p.x = j;
			}
		}
	}
}

bool	is_parsing_valid(char c)
{
	char	*valid_char;
	int		i;

	i = 0;
	valid_char = "01CEP";
	while (valid_char[i] != '\0')
	{	
		if (c == valid_char[i])
			return (true);
		i++;
	}
	return (false);
}
