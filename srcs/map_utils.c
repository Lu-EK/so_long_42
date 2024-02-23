/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lellong- < lellong-@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:49:47 by lellong-          #+#    #+#             */
/*   Updated: 2023/05/03 18:12:43 by lellong-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/so_long.h"

char	**malloc_tableau(t_data *data, char **map)
{
	int	i;
	int	cols;
	int	rows;

	i = 0;
	map = NULL;
	rows = number_of_row(data->filename);
	cols = number_of_col(data->filename);
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	while (i < rows)
	{
		map[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

void	print_map_terminal(t_data *data, char **map)
{	
	int	j;
	int	i;

	j = 0;
	while (j < number_of_row(data->filename))
	{
		i = 0;
		while (i < number_of_col(data->filename))
		{
			ft_printf("%c ", map[j][i]);
			i++;
		}
		j++;
		ft_printf("\n");
	}
	return ;
}

int	number_of_col(char *filename)
{
	int		fd;
	char	*buffer;
	size_t	bytes_read;
	size_t	i;

	if (!filename)
		return (0);
	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{	
		free(buffer);
		exit(0);
	}
	i = 0;
	bytes_read = read(fd, buffer, 1024);
	while (i < bytes_read && buffer[i] != '\n')
		i++;
	free(buffer);
	close(fd);
	return (i);
}

static void	ft_aux(char *buffer)
{
	free(buffer);
	exit(0);
}

int	number_of_row(char *filename)
{
	int		fd;
	char	*buffer;
	int		i;
	int		j;
	int		bytes_read;

	i = 0;
	j = 0;
	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_aux(buffer);
	bytes_read = read(fd, buffer, 10000);
	while (i < bytes_read)
	{
		if (buffer[i++] == '\n')
			j++;
	}
	free(buffer);
	close(fd);
	return (j + 1);
}
