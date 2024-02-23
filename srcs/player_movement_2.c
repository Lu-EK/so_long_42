/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:23:04 by lellong-          #+#    #+#             */
/*   Updated: 2023/06/14 11:30:46 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

void	player_wrong_exit(t_data *data)
{
	data->map[data->p_p.y][data->p_p.x] = '0';
	print_image(data, IM_0, (data->p_p.x) *(SW),
		(((data->p_p.y)) *(SH)));
	if (data->last_movement == 'D')
		data->p_p.x += 1;
	else if (data->last_movement == 'A')
		data->p_p.x -= 1;
	else if (data->last_movement == 'W')
		data->p_p.y -= 1;
	else if (data->last_movement == 'S')
		data->p_p.y += 1;
	data->map[data->p_p.y][(data->p_p.x)] = 'W';
	print_image(data, IM_WE, (data->p_p.x) *(SW),
		(((data->p_p.y)) *(SH)));
	return ;
}

void	re_print_exit_3(t_data *data)
{	
	data->map[data->p_p.y][data->p_p.x] = 'W';
	print_image(data, IM_WE, (data->p_p.x) *(SW),
		(((data->p_p.y)) *(SH)));
	data->map[data->p_p.y][(data->p_p.x)] = 'P';
	print_image(data, IM_P, (data->p_p.x) *(SW),
		(((data->p_p.y)) *(SH)));
}

bool	re_print_exit_2(t_data *data)
{
	if (data->last_movement == 'D'
		&& data->map[data->p_p.y][data->p_p.x + 1] != '1')
	{
		data->map[data->p_p.y][data->p_p.x] = 'E';
		print_image(data, IM_E, (data->p_p.x) *(SW),
			(((data->p_p.y)) *(SH)));
		data->p_p.x += 1;
		return (true);
	}
	else if (data->last_movement == 'A'
		&& data->map[data->p_p.y][data->p_p.x - 1] != '1')
	{
		data->map[data->p_p.y][data->p_p.x] = 'E';
		print_image(data, IM_E, (data->p_p.x) *(SW),
			(((data->p_p.y)) *(SH)));
		data->p_p.x -= 1;
		return (true);
	}
	return (false);
}

void	re_print_exit(t_data *data)
{
	if (re_print_exit_2(data) == false)
	{
		if (data->last_movement == 'W'
			&& data->map[data->p_p.y - 1][data->p_p.x] != '1')
		{
			data->map[data->p_p.y][data->p_p.x] = 'E';
			print_image(data, IM_E, (data->p_p.x) *(SW),
				(((data->p_p.y)) *(SH)));
				data->p_p.y -= 1;
		}
		else if (data->last_movement == 'S'
			&& data->map[data->p_p.y + 1][data->p_p.x] != '1')
		{
			data->map[data->p_p.y][data->p_p.x] = 'E';
			print_image(data, IM_E, (data->p_p.x) *(SW),
				(((data->p_p.y)) *(SH)));
			data->p_p.y += 1;
		}
	}
	re_print_exit_3(data);
	return ;
}
