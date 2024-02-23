/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:07:27 by lellong-          #+#    #+#             */
/*   Updated: 2023/07/17 08:39:01 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

bool	is_map_valid2(t_data *data, int l, int m)
{
	int		positiondepart;
	int		sortie;
	bool	item;

	positiondepart = 0;
	sortie = 0;
	item = false;
	while (++l < number_of_row(data->filename))
	{
		m = 0;
		while (++m < number_of_col(data->filename))
		{
			if (data->map[l][m] == 'P')
				positiondepart += 1;
			else if (data->map[l][m] == 'E')
				sortie += 1;
			else if (data->map[l][m] == 'C')
				item = true;
			else if (is_parsing_valid(data->map[l][m]) == false)
				return (false);
		}
	}
	if (positiondepart != 1 || sortie != 1 || item == false)
		return (false);
	return (true);
}

bool	is_map_valid(char **map, int hauteur, int longueur)
{
	size_t	longueurligne;
	int		i;

	longueurligne = ft_strlen(map[0]);
	i = 0;
	while (i++ < hauteur - 1)
	{
		if (ft_strlen(map[i]) != longueurligne)
			return (false);
	}
	i = 0;
	while (i < longueur)
	{
		if (map[0][i] != '1' || map[hauteur -1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < hauteur - 1)
	{
		if (map[i][0] != '1' || map[i][longueur -1] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	fill_arrays(t_data *data)
{
	data->delta_row[0] = -1;
	data->delta_row[1] = 1;
	data->delta_row[2] = 0;
	data->delta_row[3] = 0;
	data->delta_col[0] = 0;
	data->delta_col[1] = 0;
	data->delta_col[2] = -1;
	data->delta_col[3] = 1;
	return ;
}

int	has_valid_path(t_data *data, int row, int col, int i)
{
	char	cell;
	int		new_row;
	int		new_col;
	int		found;

	fill_arrays(data);
	cell = data->verif_map[row][col];
	found = 0;
	if (cell == 'K')
		return (0);
	if (cell == '1')
		return (0);
	if (cell == 'E')
		return (1);
	data->verif_map[row][col] = 'K';
	while (found == 0 && i < 4)
	{
		new_row = row + data->delta_row[i];
		new_col = col + data->delta_col[i];
		found = has_valid_path(data, new_row, new_col, 0);
		i++;
	}
	return (found);
}

int	all_valid(t_data *data, char *filename)
{
	data->verif_map = copy_map(data);
	if (is_map_valid(data->map, number_of_row(filename),
			number_of_col(filename)) == false)
	{
		ft_printf("Error\nWrong parameters\n");
		end(data);
	}
	if (is_map_valid2(data, -1, -1) == false)
	{
		ft_printf("Error\nWrong parameters\n");
		end(data);
	}
	if (has_valid_extension_and_path(data->filename) == false)
	{
		ft_printf("Error\nWrong parameters\n");
		end(data);
	}
	if (has_valid_path(data, data->p_p.y, data->p_p.x, 0) == 0)
	{
		ft_printf("Error\nWrong parameters\n");
		end(data);
	}
	return (1);
}
