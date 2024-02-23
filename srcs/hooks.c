/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:09:25 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/26 15:24:12 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

void	print_count_panel(t_data *data, int mov)
{
	char	*count;

	count = ft_itoa(mov);
	print_image(data, IM_1, -50, -50);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 25, 25, 0xFF00, count);
	free(count);
}

void	handle_keypress_util(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		printf("touche esc ; %d\n", keysym);
		end(data);
	}
	else if (keysym == 119)
	{
		data->last_movement = 'W';
		player_moves_up(data);
	}
	else if (keysym == 97)
	{
		data->last_movement = 'A';
		player_moves_left(data);
	}
	else if (keysym == 100)
	{
		data->last_movement = 'D';
		player_moves_right(data);
	}
	else if (keysym == 115)
	{
		data->last_movement = 'S';
		player_moves_down(data);
	}
	else
		handle_no_event(data);
}

int	handle_keypress(int keysym, t_data *data)
{
	handle_keypress_util(keysym, data);
	print_count_panel(data, data->m_counter);
	return (0);
}

int	handle_no_event(void *data)
{
	if (data)
		return (0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button)
	{
		x = y;
		data->collectibles += 0;
	}
	return (1);
}
