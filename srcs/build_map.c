/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:07:52 by lellong-          #+#    #+#             */
/*   Updated: 2023/04/24 16:33:33 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

char	**get_array(char *filename, t_data *data)
{
	data->fd_map = 0;
	data->window_ptr = NULL;
	data->mlx_ptr = NULL;
	data->filename = filename;
	data->fd_map = open(filename, O_RDONLY);
	if (data->fd_map == -1)
	{
		ft_printf("Error\nWrong parameters\n");
		exit(0);
	}
	data->m_counter = 0;
	data->map = malloc_tableau(data, data->map);
	if (!data->map)
	{
		ft_printf("Error\nWrong parameters\n");
		exit(0);
	}
	return (data->map);
}

void	read_map(t_data *data, char *buffer, int x, int y)
{
	size_t	bytes_read;
	size_t	i;

	i = 0;
	bytes_read = 0;
	while ((bytes_read == 0 && x < MAX_WINDOW && y < MAX_WINDOW))
	{
		bytes_read = read(data->fd_map, buffer, MAX_WINDOW);
		buffer[bytes_read] = '\0';
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
			{
				data->map[y++][x] = '\0';
				x = 0;
			}
			else
				data->map[y][x++] = buffer[i];
			i++;
		}
		data->map[y][x] = '\0';
		if (data->map[0][0] == '\0')
			check_map_empty(data, buffer);
	}
}

char	**file_to_array(t_data *data)
{
	char	*buffer;

	data->map = get_array(data->filename, data);
	if (data->fd_map == -1)
	{
		ft_printf("Error\nWrong parameters\n");
		exit(0);
	}
	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (NULL);
	read_map(data, buffer, 0, 0);
	free(buffer);
	buffer = NULL;
	count_collectibles(data);
	close(data->fd_map);
	return (data->map);
}

void	count_collectibles(t_data *data)
{
	int	j;
	int	i;

	data->collectibles = 0;
	j = 0;
	while (j < number_of_row(data->filename))
	{
		i = 0;
		while (i < number_of_col(data->filename))
		{
			if (data->map[j][i] == 'C')
				data->collectibles++;
			i++;
		}
		j++;
	}
	return ;
}

void	draw_board(char **board, t_data *data, int y, int x)
{
	while (y < number_of_row(data->filename))
	{
		x = 0;
		while (x < number_of_col(data->filename))
		{
			if (board[y][x] == '1')
				print_image(data, IM_1, (x) *(SW), (y) *(SH));
			else if (board[y][x] == '0')
				print_image(data, IM_0, (x) *(SW), (y) *(SH));
			else if (board[y][x] == 'C')
				print_image(data, IM_C, (x) *(SW), (y) *(SH));
			else if (board[y][x] == 'P')
			{
				print_image(data, IM_P, (x) *(SW), (y) *(SH));
				data->p_p.y = y;
				data->p_p.x = x;
			}
			else if (board[y][x] == 'E')
				print_image(data, IM_E, (x) *(SW), (y) *(SH));
			x++;
		}
		y++;
	}
}
