/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:08:49 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/29 16:50:37 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

int	player_moves_right(t_data *data)
{
	if (data->map[data->p_p.y][(data->p_p.x + 1)] == 'E')
	{
		if (data->collectibles > 0)
		{
			player_wrong_exit(data);
			data->m_counter++;
			return (0);
		}
		else
			end(data);
	}
	if (data->map[data->p_p.y][(data->p_p.x)] == 'W')
		return (re_print_exit(data), 1);
	if (data->map[data->p_p.y][(data->p_p.x) + 1] != '1')
	{
		data->map[data->p_p.y][data->p_p.x] = '0';
		print_image(data, IM_0, (data->p_p.x) *(SW), (((data->p_p.y)) *(SH)));
		if (data->map[data->p_p.y][(data->p_p.x) + 1] == 'C')
			data->collectibles -= 1;
		data->p_p.x += 1;
		data->map[data->p_p.y][data->p_p.x] = 'P';
		print_image(data, IM_P, (data->p_p.x) *(SW), (((data->p_p.y)) *(SH)));
		data->m_counter++;
	}
	return (1);
}

int	player_moves_left(t_data *data)
{
	if (data->map[data->p_p.y][(data->p_p.x - 1)] == 'E')
	{
		if (data->collectibles > 0)
		{
			player_wrong_exit(data);
			data->m_counter++;
			return (0);
		}
		else
			end(data);
	}
	if (data->map[data->p_p.y][(data->p_p.x)] == 'W')
		return (re_print_exit(data), 1);
	if (data->map[data->p_p.y][(data->p_p.x) - 1] != '1')
	{
		data->map[data->p_p.y][(data->p_p.x)] = '0';
		print_image(data, IM_0, (data->p_p.x) *(SW), (((data->p_p.y)) *(SH)));
		if (data->map[data->p_p.y][(data->p_p.x) - 1] == 'C')
			data->collectibles -= 1;
		data->p_p.x -= 1;
		data->map[data->p_p.y][data->p_p.x] = 'P';
		print_image(data, IM_P, (data->p_p.x) *(SW), (((data->p_p.y)) *(SH)));
		data->m_counter++;
	}
	return (1);
}

int	player_moves_up(t_data *data)
{
	if (data->map[data->p_p.y - 1][(data->p_p.x)] == 'E' )
	{
		if (data->collectibles > 0)
		{
			player_wrong_exit(data);
			data->m_counter++;
			return (0);
		}
		else
			end(data);
	}
	if (data->map[data->p_p.y][(data->p_p.x)] == 'W')
		return (re_print_exit(data), 1);
	if (data->map[data->p_p.y - 1][(data->p_p.x)] != '1')
	{
		data->map[data->p_p.y][(data->p_p.x)] = '0';
		print_image(data, IM_0, (data->p_p.x) *(SW), (((data->p_p.y)) *(SH)));
		if (data->map[data->p_p.y - 1][(data->p_p.x)] == 'C')
			data->collectibles -= 1;
		data->p_p.y -= 1;
		data->map[data->p_p.y][data->p_p.x] = 'P';
		print_image(data, IM_P, (data->p_p.x) *(SW), (((data->p_p.y)) *(SH)));
		data->m_counter++;
	}
	return (1);
}

int	player_moves_down(t_data *data)
{
	if (data->map[data->p_p.y + 1][(data->p_p.x)] == 'E' )
	{
		if (data->collectibles > 0)
		{
			player_wrong_exit(data);
			data->m_counter++;
			return (0);
		}
		else
			end(data);
	}
	if (data->map[data->p_p.y][(data->p_p.x)] == 'W')
		return (re_print_exit(data), 1);
	if (data->map[data->p_p.y + 1][(data->p_p.x)] != '1')
	{
		data->map[data->p_p.y][(data->p_p.x)] = '0';
		print_image(data, IM_0, (data->p_p.x) *(SW), (((data->p_p.y)) *(SH)));
		if (data->map[data->p_p.y + 1][(data->p_p.x)] == 'C')
			data->collectibles -= 1;
		data->p_p.y += 1;
		data->map[data->p_p.y][data->p_p.x] = 'P';
		print_image(data, IM_P, (data->p_p.x) *(SW), (((data->p_p.y)) *(SH)));
		data->m_counter++;
	}
	return (1);
}
