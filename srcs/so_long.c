/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:21:17 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/04 13:36:40 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (start_game(&data, argc, argv) != 1)
		exit(0);
	mlx_hook(data.window_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.window_ptr, WINDOW_CLOSED,
		LeaveWindowMask, &end, &data);
	mlx_mouse_hook(data.window_ptr, &mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
