/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:39:27 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/28 14:19:14 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

void	free_image(t_image *image, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, image->address);
	mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	mlx_destroy_display(data->mlx_ptr);
	return ;
}

int	end(t_data *data)
{
	int		i;
	int		rows;

	i = 0;
	rows = number_of_row(data->filename);
	if (data->map != NULL)
	{
		while (i < rows)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	if (data->verif_map)
		free_map(data, data->verif_map);
	if (data->window_ptr)
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
}
