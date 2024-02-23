/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:53:16 by lellong-          #+#    #+#             */
/*   Updated: 2023/07/17 08:39:12 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

int	start_game(t_data *data, int argc, char **argv)
{
	if (argc > 2 || !argv[1])
	{
		ft_printf("Error\nWrong parameters\n");
		exit (0);
	}
	data->filename = argv[1];
	data->map = file_to_array(data);
	all_valid(data, data->filename);
	data->mlx_ptr = mlx_init();
	data->window_ptr = mlx_new_window(data->mlx_ptr, number_of_col
			(data->filename) *(50), number_of_row(data->filename) *(50), "CP3");
	draw_board(data->map, data, 0, 0);
	return (1);
}
